#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MQTTAsync.h"

#include <unistd.h>   //for sleep
#include "gattlib.h"  //for BLE
#include <assert.h>
#include <pthread.h>  //for thread
#include "frozen.h"   //for json messages

#include <glib.h>

#include "time.h"

//MQTT
#define ADDRESS           "tcp://localhost:1883"
#define CLIENTID          "ClientBLE"
#define TOPIC_turn		  "Plug/+/turn"
#define TOPIC_1_turn      "Plug/1/turn"           //Topic to which I'm going to subscribe
#define TOPIC_1_current   "Plug/1/current"
#define TOPIC_2_turn      "Plug/2/turn"           //Topic to which I'm going to subscribe
#define TOPIC_temperature "Sensor/temperature"
#define TOPIC_movement    "Sensor/movement"
#define QOS        1
#define TIMEOUT    10000L

volatile MQTTAsync_token deliveredtoken;
MQTTAsync client;

//BLE
static uuid_t g_uuid[2][4];
static char *g_uuid_data[2][4] = {{ "0xA001", "0xA002", "0xA003", "0xA004"},
									{"0xB001", "0xB002", "0xB003", "0xB004"}};

unsigned char value_data;
gatt_connection_t* connection [2];

const char *MAC_device [] = {"D5:0A:3A:07:5D:51", "EC:E0:03:04:BD:F8"};//sensor, plug

char *Read_From_Device [] =         { "D5:0A:3A:07:5D:51", "read", "0xA001"};
char *Write_to_Device [] =          { "D5:0A:3A:07:5D:51", "write", "0xA002"};
char *Notification_From_Device [] = { "D5:0A:3A:07:5D:51", "notification", "0xA003"};
char *Movement_from_Device [] =     { "D5:0A:3A:07:5D:51", "movement", "0xA004"};

typedef enum { READ, WRITE} operation_t;
operation_t g_operation;

enum states
{
	connecting_MQTT,
	connecting_BLE,
	suscribing_MQTT,
	notification_active,
	BLE_error,
	MQTT_error,
	BLE_reconnection,
	MQTT_connection_lost,
	MQTT_error_init,

} a_state;

void delay(unsigned int milliseconds){
	clock_t start = clock();

	while((clock()-start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}

void onDisconnect(void* context, MQTTAsync_successData* response)
{
	printf("Successful disconnection\n");
}

static void usage(char *argv[])
{
	printf("%s <device_address>\n", argv[0]);
}

void onSend(void* context, MQTTAsync_successData* response)
{
	printf("Message with token value %d delivery confirmed\n", response->token);
}

void connlost(void *context, char *cause)
{
	a_state = MQTT_connection_lost;
	MQTTAsync client = (MQTTAsync)context;
	MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;
	int rc;
	printf("\nConnection lost cause: %s\n", cause);
	printf("Reconnecting\n");
	conn_opts.keepAliveInterval = 20;
	conn_opts.cleansession = 1;
	if ((rc = MQTTAsync_connect(client, &conn_opts)) != MQTTASYNC_SUCCESS)
	{
		printf("Failed to start connect, return code %d\n", rc);
	}
}

void onConnectFailure(void* context, MQTTAsync_failureData* response)
{
	printf("Connect failed, rc %d\n", response ? response->code : 0);
}

void notification_handler(const uuid_t* uuid, const uint8_t* data, size_t data_length, void* user_data){
	a_state = notification_active;

	int i;

	printf("Notification Handler: ");

	for (i = 0; i < data_length; i++) {

		printf("%02x ", data[i]);
	}
	printf("\n");

	//To cast integer to array
	char buffer_array [] = "99999";
	sprintf(buffer_array, "%d", data[0]);

	char buffer_array2 [] = "99999";
	int aux = data[0]*220;
	sprintf(buffer_array2, "%d", (aux));

	//To cast array to json message
	char json_buffer[100];
	struct json_out out1 = JSON_OUT_BUF(json_buffer, sizeof(json_buffer));
	//Restart out1, otherwise prints will accumulate
	json_printf(&out1,"{ current : %Q, watts: %Q}",buffer_array, buffer_array2);
	//it could continue to be cumulative

	MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
	MQTTAsync_message pubmsg = MQTTAsync_message_initializer;

	int rc;
	opts.onFailure = onConnectFailure;
	opts.onSuccess = onSend;
	opts.context = client;

	pubmsg.payload = json_buffer;
	pubmsg.payloadlen = strlen(json_buffer);
	pubmsg.qos = QOS;
	pubmsg.retained = 0;
	deliveredtoken = 0;

	if ((rc = MQTTAsync_sendMessage(client, TOPIC_1_current, &pubmsg, &opts)) != MQTTASYNC_SUCCESS)
	{
		printf("Failed to start sendMessage, return code %d\n", rc);
		a_state = MQTT_error;
		exit(EXIT_FAILURE);
	}

}

void notification_handler2(const uuid_t* uuid, const uint8_t* data, size_t data_length, void* user_data)
{
	a_state = notification_active;

	if(gattlib_uuid_cmp(&g_uuid[0][2], uuid) == 0){
		int i;

		printf("Notification Handler2: ");

		for (i = 0; i < data_length; i++) {

			printf("%02x ", data[i]);
		}
		printf("\n");

		//To cast integer to array
		char buffer_array [] = "99";
		int aux = data[0];
		sprintf(buffer_array, "%d", aux);
		char buffer_array2 [] = "99";
		aux = data[1];
		sprintf(buffer_array2, "%d", aux);

		//To cast array to json message
		char json_buffer[100];
		struct json_out out1 = JSON_OUT_BUF(json_buffer, sizeof(json_buffer));
		//Restart out1, otherwise prints will accumulate
		json_printf(&out1,"{ temperature : %Q, humidity: %Q}",buffer_array, buffer_array2);
		//it could continue to be cumulative

		MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
		MQTTAsync_message pubmsg = MQTTAsync_message_initializer;

		int rc;
		opts.onFailure = onConnectFailure;
		opts.onSuccess = onSend;
		opts.context = client;

		pubmsg.payload = json_buffer;
		pubmsg.payloadlen = strlen(json_buffer);
		pubmsg.qos = QOS;
		pubmsg.retained = 0;
		deliveredtoken = 0;

		if ((rc = MQTTAsync_sendMessage(client, TOPIC_temperature, &pubmsg, &opts)) != MQTTASYNC_SUCCESS)
		{
			printf("Failed to start sendMessage, return code %d\n", rc);
			a_state = MQTT_error;
			exit(EXIT_FAILURE);
		}
	}

	if(gattlib_uuid_cmp(&g_uuid[0][3], uuid) == 0){
		int i;

		printf("Movement!!!\n ");

		for (i = 0; i < data_length; i++) {

			printf("%02x ", data[i]);
		}
		printf("\n");

		char buffer_array [] = "off";

		if( data[0] == 0){
			//To cast integer to array
			sprintf(buffer_array, "%s", "on");
		}

		MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
		MQTTAsync_message pubmsg = MQTTAsync_message_initializer;

		int rc;
		opts.onFailure = onConnectFailure;
		opts.onSuccess = onSend;
		opts.context = client;

		pubmsg.payload = buffer_array;
		pubmsg.payloadlen = strlen(buffer_array);
		pubmsg.qos = QOS;
		pubmsg.retained = 0;
		deliveredtoken = 0;

		if ((rc = MQTTAsync_sendMessage(client, TOPIC_movement, &pubmsg, &opts)) != MQTTASYNC_SUCCESS)
		{
			printf("Failed to start sendMessage, return code %d\n", rc);
			a_state = MQTT_error;
			exit(EXIT_FAILURE);
		}
	}
}

void reconnection_BLE (int t_connection){

	printf("Reconection Plug %d \n", t_connection);

	for (int i = 0; i < 2; ++i) {
		gattlib_disconnect(connection[i]);
	}

	for (int i = 0; i < 2; ++i)
	{
		//BLE Connection
		connection[i] = gattlib_connect(NULL, MAC_device[i], BDADDR_LE_RANDOM, BT_SEC_LOW, 0, 0);
		if (connection[i] == NULL) {
			fprintf(stderr, "Fail to connect to the bluetooth device %d \n", i);
			a_state = BLE_error;
			exit(EXIT_FAILURE);
		}else {
			printf("Successful bluetooth connection %d \n", i);
		}

	}

	for (int i = 0; i < 2; ++i) {
		gattlib_disconnect(connection[i]);
		if(t_connection == 0) {
			gattlib_register_notification(connection[i], notification_handler2, NULL);
		}else{
			gattlib_register_notification(connection[i], notification_handler, NULL);
		}
	}
}

int read_write_function(char *message[], int value, int t_connection) {

	uint8_t buffer[100];
	int i, ret;
	size_t len;

	if (strcmp(message[1], "read") == 0) {
		g_operation = READ;

	} else if ((strcmp(message[1], "write") == 0)) {
		g_operation = WRITE;

		printf("Value to write: 0x%i\n", (int)value);

	} else{
		usage(message);
		return 1;
	}

	if (g_operation == READ) {

		ret = gattlib_read_char_by_uuid(connection[t_connection], &g_uuid[t_connection][0], buffer, &len);
		if(ret){
			a_state = BLE_reconnection;
			reconnection_BLE(t_connection);
		}
		else{
			printf("Read UUID completed: ");
			for (i = 0; i < len; i++)
				printf("%02x ", buffer[i]);
			printf("\n");
		}

	}else if (g_operation == WRITE){

		ret = gattlib_write_char_by_uuid(connection[t_connection], &g_uuid[t_connection][1], &value, sizeof(value));

		if(ret){
			a_state = BLE_reconnection;
			reconnection_BLE(t_connection);
		}
	}

	return 0;
}

//This callback is executed when a message arrives
int onMsgArrived(void *context, char *topicName, int topicLen, MQTTAsync_message *message)
{
	int value = 2;
	int t_connection;

	printf("Message arrived\n");
	printf("     topic: %s\n", topicName);
	printf("   message: ");

	if(strcmp(topicName,TOPIC_2_turn)== 0){
		t_connection = 0;
	}
	else if(strcmp(topicName,TOPIC_1_turn) == 0){
		t_connection = 1;
	}

	//json_scanf decodes JSON message
	//you would call it 3 times to get 3 different messages
	if (json_scanf(message->payload, message->payloadlen, "%d", &value)==1)
	{

		printf("Value: [%d] \n",value);
		fflush(stdout);

		//Read
		if(value == 2){
			read_write_function(Read_From_Device, value, t_connection);
		}
		//Write 0 or 1
		else if((value == 0) || (value == 1)){
			read_write_function(Write_to_Device, value, t_connection);
		}

	}
	else
	{
		printf("Message JSON was not decoded correctly  \n");
	}

	//to release the message
	MQTTAsync_freeMessage(&message);
	MQTTAsync_free(topicName);

	return 1;
}

void onSubscribeFailure(void* context, MQTTAsync_failureData* response)
{
	printf("Subscribe failed, rc %d\n", response ? response->code : 0);
}

void onSubscribe(void* context, MQTTAsync_successData* response)
{
	printf("MQTT Subscribe succeeded\n");
	printf("Connecting BLE\n");
	a_state = connecting_BLE;

	int i = 0;
	int ret = 0;

	for (i = 0; i < 2; ++i)
	{
		//BLE Connection
		connection[i] = gattlib_connect(NULL, MAC_device[i], BDADDR_LE_RANDOM, BT_SEC_LOW, 0, 0);
		if (connection[i] == NULL) {
			fprintf(stderr, "Fail to connect to the bluetooth device %d \n", i);
			a_state = BLE_error;
			exit(EXIT_FAILURE);
		}else {
			printf("Successful bluetooth connection %d \n", i);
		}
	}

	for(i = 0; i < 2; i++){
		for (int j = 0; j < 4; j++) {

			if (gattlib_string_to_uuid(g_uuid_data[i][j], strlen(g_uuid_data[i][j]) + 1, &g_uuid[i][j]) < 0) {
				a_state = BLE_error;
				exit(EXIT_FAILURE);
			}
		}
	}

	for (i = 0; i < 2; ++i) {

		if (i == 0){
			gattlib_register_notification(connection[i], notification_handler2, NULL);
		}else if(i == 1){
			gattlib_register_notification(connection[i], notification_handler, NULL);
		}

	}

	ret = gattlib_notification_start(connection[0], &g_uuid[0][2]);
	if (ret) {
		fprintf(stderr, "Fail to start notification\n.");
		//a_state = BLE_error;
		//exit(EXIT_FAILURE);
	}else{
		printf("Succes to start notification %d \n", 0);
	}

	ret = gattlib_notification_start(connection[0], &g_uuid[0][3]);
	if (ret) {
		fprintf(stderr, "Fail to start movement\n");
		a_state = BLE_error;
		//exit(EXIT_FAILURE);
	}else{
		printf("Succes to start movement\n");
	}
	ret = gattlib_notification_start(connection[1], &g_uuid[1][2]);
	if (ret) {
		fprintf(stderr, "Fail to start notification %d \n", 1);
		a_state = BLE_error;
		//exit(EXIT_FAILURE);
	}else{
		printf("succes to start notification %d \n", 1);
	}
}

void onConnect(void* context, MQTTAsync_successData* response)
{
	printf("Successful MQTT connection\n");
	a_state = suscribing_MQTT;

	MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
	int rc;

	printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n", TOPIC_turn, CLIENTID, QOS);
	opts.onSuccess = onSubscribe; //This callback function will be executed when the subscription has been made correctly
	opts.onFailure = onSubscribeFailure;
	opts.context = client;

	deliveredtoken = 0;
	//Make the subscription request
	if ((rc = MQTTAsync_subscribe(client, TOPIC_turn, QOS, &opts)) != MQTTASYNC_SUCCESS)
	{
		printf("Failed to start subscribe, return code %d\n", rc);
		a_state = MQTT_error;
		exit(-1);
	}
}

int main(int argc, char* argv[])
{
	int rc;
	a_state = connecting_MQTT;

	MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;

	MQTTAsync_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
	MQTTAsync_setCallbacks(client, NULL, connlost, onMsgArrived, NULL);

	conn_opts.keepAliveInterval = 80;
	conn_opts.cleansession = 1;
	conn_opts.onSuccess = onConnect;
	conn_opts.onFailure = onConnectFailure;
	conn_opts.context = client;

	//Connect with MQTT server
	//MQTT create a thread
	if ((rc = MQTTAsync_connect(client, &conn_opts)) != MQTTASYNC_SUCCESS)
	{
		printf("Failed to start connect, return code %d\n", rc);
		a_state = MQTT_error;
		exit(EXIT_FAILURE);
	}


	GMainLoop *loop = g_main_loop_new(NULL, 0);
	g_main_loop_run(loop);

	g_main_loop_unref(loop);

	//AQUI NO LLEGA NUNCA NO?
	gattlib_disconnect(connection[0]);
	gattlib_disconnect(connection[1]);
	MQTTAsync_destroy(&client);
	return rc;
}
