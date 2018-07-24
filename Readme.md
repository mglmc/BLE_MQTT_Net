
The main target of this project is the development of a **network of smart devices with BLE connectivity**, intended to support home automation applications.

As an application example of smart device into the BLE network. It has been created a Smart Plug. [mglmc/archBLE_plug.git](https://github.com/mglmc/archBLE_plug.git)

* Developed in Eclipse IDE.
* It uses **JSON** (by _frozen_ library) format to send the data by **MQTT** (_MQTTAsync_ library) protocol.
* To manage the different BLE devices uses _gattlib_ library.
* As a web interface uses _Home Assistant_ platform (it'll be upload soon) but it can be integrated in any interface that uses MQTT protocol.

There are 2 different main code:
* **BLE_MQTT_one_device** : only manage one BLE device at the same time, but if the connection fails it could be reconnected sending a read/write request.
* **BLE_MQTT_several_devices** : the code can manage several devices at the same time but if the connection fails the reconnection mode doesn't work (that is a cause the _gattlib_ library has some issues).


...Developing readme...
