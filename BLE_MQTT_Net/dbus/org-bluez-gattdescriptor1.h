/*
 * Generated by gdbus-codegen 2.50.3. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#ifndef ___HOME_CANO_DESKTOP_GATTLIB_MASTER_BUILD_DBUS_ORG_BLUEZ_GATTDESCRIPTOR1_H__
#define ___HOME_CANO_DESKTOP_GATTLIB_MASTER_BUILD_DBUS_ORG_BLUEZ_GATTDESCRIPTOR1_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for org.bluez.GattDescriptor1 */

#define TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1 (org_bluez_gatt_descriptor1_get_type ())
#define ORG_BLUEZ_GATT_DESCRIPTOR1(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1, OrgBluezGattDescriptor1))
#define IS_ORG_BLUEZ_GATT_DESCRIPTOR1(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1))
#define ORG_BLUEZ_GATT_DESCRIPTOR1_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1, OrgBluezGattDescriptor1Iface))

struct _OrgBluezGattDescriptor1;
typedef struct _OrgBluezGattDescriptor1 OrgBluezGattDescriptor1;
typedef struct _OrgBluezGattDescriptor1Iface OrgBluezGattDescriptor1Iface;

struct _OrgBluezGattDescriptor1Iface
{
  GTypeInterface parent_iface;



  gboolean (*handle_read_value) (
    OrgBluezGattDescriptor1 *object,
    GDBusMethodInvocation *invocation,
    GVariant *arg_options);

  gboolean (*handle_write_value) (
    OrgBluezGattDescriptor1 *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_value,
    GVariant *arg_options);

  const gchar * (*get_characteristic) (OrgBluezGattDescriptor1 *object);

  const gchar * (*get_uuid) (OrgBluezGattDescriptor1 *object);

  const gchar * (*get_value) (OrgBluezGattDescriptor1 *object);

  void (*properties_changed) (
    OrgBluezGattDescriptor1 *object,
    const gchar *arg_interface,
    GVariant *arg_changed_properties,
    const gchar *const *arg_invalidated_properties);

};

GType org_bluez_gatt_descriptor1_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *org_bluez_gatt_descriptor1_interface_info (void);
guint org_bluez_gatt_descriptor1_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void org_bluez_gatt_descriptor1_complete_read_value (
    OrgBluezGattDescriptor1 *object,
    GDBusMethodInvocation *invocation,
    const gchar *value);

void org_bluez_gatt_descriptor1_complete_write_value (
    OrgBluezGattDescriptor1 *object,
    GDBusMethodInvocation *invocation);



/* D-Bus signal emissions functions: */
void org_bluez_gatt_descriptor1_emit_properties_changed (
    OrgBluezGattDescriptor1 *object,
    const gchar *arg_interface,
    GVariant *arg_changed_properties,
    const gchar *const *arg_invalidated_properties);



/* D-Bus method calls: */
void org_bluez_gatt_descriptor1_call_read_value (
    OrgBluezGattDescriptor1 *proxy,
    GVariant *arg_options,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean org_bluez_gatt_descriptor1_call_read_value_finish (
    OrgBluezGattDescriptor1 *proxy,
    gchar **out_value,
    GAsyncResult *res,
    GError **error);

gboolean org_bluez_gatt_descriptor1_call_read_value_sync (
    OrgBluezGattDescriptor1 *proxy,
    GVariant *arg_options,
    gchar **out_value,
    GCancellable *cancellable,
    GError **error);

void org_bluez_gatt_descriptor1_call_write_value (
    OrgBluezGattDescriptor1 *proxy,
    const gchar *arg_value,
    GVariant *arg_options,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean org_bluez_gatt_descriptor1_call_write_value_finish (
    OrgBluezGattDescriptor1 *proxy,
    GAsyncResult *res,
    GError **error);

gboolean org_bluez_gatt_descriptor1_call_write_value_sync (
    OrgBluezGattDescriptor1 *proxy,
    const gchar *arg_value,
    GVariant *arg_options,
    GCancellable *cancellable,
    GError **error);



/* D-Bus property accessors: */
const gchar *org_bluez_gatt_descriptor1_get_uuid (OrgBluezGattDescriptor1 *object);
gchar *org_bluez_gatt_descriptor1_dup_uuid (OrgBluezGattDescriptor1 *object);
void org_bluez_gatt_descriptor1_set_uuid (OrgBluezGattDescriptor1 *object, const gchar *value);

const gchar *org_bluez_gatt_descriptor1_get_characteristic (OrgBluezGattDescriptor1 *object);
gchar *org_bluez_gatt_descriptor1_dup_characteristic (OrgBluezGattDescriptor1 *object);
void org_bluez_gatt_descriptor1_set_characteristic (OrgBluezGattDescriptor1 *object, const gchar *value);

const gchar *org_bluez_gatt_descriptor1_get_value (OrgBluezGattDescriptor1 *object);
gchar *org_bluez_gatt_descriptor1_dup_value (OrgBluezGattDescriptor1 *object);
void org_bluez_gatt_descriptor1_set_value (OrgBluezGattDescriptor1 *object, const gchar *value);


/* ---- */

#define TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1_PROXY (org_bluez_gatt_descriptor1_proxy_get_type ())
#define ORG_BLUEZ_GATT_DESCRIPTOR1_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1_PROXY, OrgBluezGattDescriptor1Proxy))
#define ORG_BLUEZ_GATT_DESCRIPTOR1_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1_PROXY, OrgBluezGattDescriptor1ProxyClass))
#define ORG_BLUEZ_GATT_DESCRIPTOR1_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1_PROXY, OrgBluezGattDescriptor1ProxyClass))
#define IS_ORG_BLUEZ_GATT_DESCRIPTOR1_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1_PROXY))
#define IS_ORG_BLUEZ_GATT_DESCRIPTOR1_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1_PROXY))

typedef struct _OrgBluezGattDescriptor1Proxy OrgBluezGattDescriptor1Proxy;
typedef struct _OrgBluezGattDescriptor1ProxyClass OrgBluezGattDescriptor1ProxyClass;
typedef struct _OrgBluezGattDescriptor1ProxyPrivate OrgBluezGattDescriptor1ProxyPrivate;

struct _OrgBluezGattDescriptor1Proxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  OrgBluezGattDescriptor1ProxyPrivate *priv;
};

struct _OrgBluezGattDescriptor1ProxyClass
{
  GDBusProxyClass parent_class;
};

GType org_bluez_gatt_descriptor1_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (OrgBluezGattDescriptor1Proxy, g_object_unref)
#endif

void org_bluez_gatt_descriptor1_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
OrgBluezGattDescriptor1 *org_bluez_gatt_descriptor1_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
OrgBluezGattDescriptor1 *org_bluez_gatt_descriptor1_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void org_bluez_gatt_descriptor1_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
OrgBluezGattDescriptor1 *org_bluez_gatt_descriptor1_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
OrgBluezGattDescriptor1 *org_bluez_gatt_descriptor1_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1_SKELETON (org_bluez_gatt_descriptor1_skeleton_get_type ())
#define ORG_BLUEZ_GATT_DESCRIPTOR1_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1_SKELETON, OrgBluezGattDescriptor1Skeleton))
#define ORG_BLUEZ_GATT_DESCRIPTOR1_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1_SKELETON, OrgBluezGattDescriptor1SkeletonClass))
#define ORG_BLUEZ_GATT_DESCRIPTOR1_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1_SKELETON, OrgBluezGattDescriptor1SkeletonClass))
#define IS_ORG_BLUEZ_GATT_DESCRIPTOR1_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1_SKELETON))
#define IS_ORG_BLUEZ_GATT_DESCRIPTOR1_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_ORG_BLUEZ_GATT_DESCRIPTOR1_SKELETON))

typedef struct _OrgBluezGattDescriptor1Skeleton OrgBluezGattDescriptor1Skeleton;
typedef struct _OrgBluezGattDescriptor1SkeletonClass OrgBluezGattDescriptor1SkeletonClass;
typedef struct _OrgBluezGattDescriptor1SkeletonPrivate OrgBluezGattDescriptor1SkeletonPrivate;

struct _OrgBluezGattDescriptor1Skeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  OrgBluezGattDescriptor1SkeletonPrivate *priv;
};

struct _OrgBluezGattDescriptor1SkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType org_bluez_gatt_descriptor1_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (OrgBluezGattDescriptor1Skeleton, g_object_unref)
#endif

OrgBluezGattDescriptor1 *org_bluez_gatt_descriptor1_skeleton_new (void);


G_END_DECLS

#endif /* ___HOME_CANO_DESKTOP_GATTLIB_MASTER_BUILD_DBUS_ORG_BLUEZ_GATTDESCRIPTOR1_H__ */