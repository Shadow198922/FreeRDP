/* Generated by  */

#include "../core/settings.h"
#include "settings_str.h"

BOOL freerdp_settings_clone_keys(rdpSettings* dst, const rdpSettings* src)
{
	WINPR_ASSERT(dst);
	WINPR_ASSERT(src);

	for (size_t x = 0; x < ARRAYSIZE(settings_map); x++)
	{
		const struct settings_str_entry* cur = &settings_map[x];
		switch (cur->type)
		{
			case FREERDP_SETTINGS_TYPE_BOOL: /* bool */
			{
				BOOL sval = freerdp_settings_get_bool(src, (FreeRDP_Settings_Keys_Bool)cur->id);
				if (!freerdp_settings_set_bool(dst, (FreeRDP_Settings_Keys_Bool)cur->id, sval))
					return FALSE;
			}
			break;
			case FREERDP_SETTINGS_TYPE_UINT16: /* UINT16 */
			{
				UINT16 sval =
				    freerdp_settings_get_uint16(src, (FreeRDP_Settings_Keys_UInt16)cur->id);
				if (!freerdp_settings_set_uint16(dst, (FreeRDP_Settings_Keys_UInt16)cur->id, sval))
					return FALSE;
			}
			break;
			case FREERDP_SETTINGS_TYPE_INT16: /* INT16 */
			{
				INT16 sval = freerdp_settings_get_int16(src, (FreeRDP_Settings_Keys_Int16)cur->id);
				if (!freerdp_settings_set_int16(dst, (FreeRDP_Settings_Keys_Int16)cur->id, sval))
					return FALSE;
			}
			break;
			case FREERDP_SETTINGS_TYPE_UINT32: /* UINT32 */
			{
				UINT32 sval =
				    freerdp_settings_get_uint32(src, (FreeRDP_Settings_Keys_UInt32)cur->id);
				if (!freerdp_settings_set_uint32(dst, (FreeRDP_Settings_Keys_UInt32)cur->id, sval))
					return FALSE;
			}
			break;
			case FREERDP_SETTINGS_TYPE_INT32: /* INT32 */
			{
				INT32 sval = freerdp_settings_get_int32(src, (FreeRDP_Settings_Keys_Int32)cur->id);
				if (!freerdp_settings_set_int32(dst, (FreeRDP_Settings_Keys_Int32)cur->id, sval))
					return FALSE;
			}
			break;
			case FREERDP_SETTINGS_TYPE_UINT64: /* UINT64 */
			{
				UINT64 sval =
				    freerdp_settings_get_uint64(src, (FreeRDP_Settings_Keys_UInt64)cur->id);
				if (!freerdp_settings_set_uint64(dst, (FreeRDP_Settings_Keys_UInt64)cur->id, sval))
					return FALSE;
			}
			break;
			case FREERDP_SETTINGS_TYPE_INT64: /* INT64 */
			{
				INT64 sval = freerdp_settings_get_int64(src, (FreeRDP_Settings_Keys_Int64)cur->id);
				if (!freerdp_settings_set_int64(dst, (FreeRDP_Settings_Keys_Int64)cur->id, sval))
					return FALSE;
			}
			break;
			case FREERDP_SETTINGS_TYPE_STRING: /* strings */
			{
				const char* sval =
				    freerdp_settings_get_string(src, (FreeRDP_Settings_Keys_String)cur->id);
				size_t len = 0;
				if (sval)
					len = strlen(sval);
				if (!freerdp_settings_set_string_copy_(dst, (FreeRDP_Settings_Keys_String)cur->id,
				                                       sval, len, FALSE))
					return FALSE;
			}
			break;
			case FREERDP_SETTINGS_TYPE_POINTER: /* pointer */
			{
				const void* sval =
				    freerdp_settings_get_pointer(src, (FreeRDP_Settings_Keys_Pointer)cur->id);
				if (!freerdp_settings_set_pointer(dst, (FreeRDP_Settings_Keys_Pointer)cur->id,
				                                  sval))
					return FALSE;
			}
			break;
		}
	}
	return TRUE;
}

BOOL freerdp_settings_print_diff(wLog* log, DWORD level, const rdpSettings* settings,
                                 const rdpSettings* other)
{
	BOOL rc = FALSE;

	WINPR_ASSERT(log);
	WINPR_ASSERT(settings);
	WINPR_ASSERT(other);

	for (size_t x = 0; x < ARRAYSIZE(settings_map); x++)
	{
		const struct settings_str_entry* cur = &settings_map[x];
		switch (cur->type)
		{
			case FREERDP_SETTINGS_TYPE_BOOL: /* bool */
			{
				BOOL sval =
				    freerdp_settings_get_bool(settings, (FreeRDP_Settings_Keys_Bool)cur->id);
				BOOL cval = freerdp_settings_get_bool(other, (FreeRDP_Settings_Keys_Bool)cur->id);
				if (sval != cval)
				{
					rc = TRUE;
					WLog_Print(log, level, "%s [BOOL]: %s -> %s", cur->str, sval ? "TRUE" : "FALSE",
					           cval ? "TRUE" : "FALSE");
				}
			}
			break;
			case FREERDP_SETTINGS_TYPE_UINT16: /* UINT16 */
			{
				UINT16 sval =
				    freerdp_settings_get_uint16(settings, (FreeRDP_Settings_Keys_UInt16)cur->id);
				UINT16 cval =
				    freerdp_settings_get_uint16(other, (FreeRDP_Settings_Keys_UInt16)cur->id);
				if (sval != cval)
				{
					rc = TRUE;
					WLog_Print(log, level, "%s [UINT16]: %" PRIu16 " -> %" PRIu16, cur->str, sval,
					           cval);
				}
			}
			break;
			case FREERDP_SETTINGS_TYPE_INT16: /* INT16 */
			{
				INT16 sval =
				    freerdp_settings_get_int16(settings, (FreeRDP_Settings_Keys_Int16)cur->id);
				INT16 cval =
				    freerdp_settings_get_int16(other, (FreeRDP_Settings_Keys_Int16)cur->id);
				if (sval != cval)
				{
					rc = TRUE;
					WLog_Print(log, level, "%s [INT16]: %" PRId16 " -> %" PRId16, cur->str, sval,
					           cval);
				}
			}
			break;
			case FREERDP_SETTINGS_TYPE_UINT32: /* UINT32 */
			{
				UINT32 sval =
				    freerdp_settings_get_uint32(settings, (FreeRDP_Settings_Keys_UInt32)cur->id);
				UINT32 cval =
				    freerdp_settings_get_uint32(other, (FreeRDP_Settings_Keys_UInt32)cur->id);
				if (sval != cval)
				{
					rc = TRUE;
					WLog_Print(log, level, "%s [UINT32]: %" PRIu32 " -> %" PRIu32, cur->str, sval,
					           cval);
				}
			}
			break;
			case FREERDP_SETTINGS_TYPE_INT32: /* INT32 */
			{
				INT32 sval =
				    freerdp_settings_get_int32(settings, (FreeRDP_Settings_Keys_Int32)cur->id);
				INT32 cval =
				    freerdp_settings_get_int32(other, (FreeRDP_Settings_Keys_Int32)cur->id);
				if (sval != cval)
				{
					rc = TRUE;
					WLog_Print(log, level, "%s [INT32]: %" PRId32 " -> %" PRId32, cur->str, sval,
					           cval);
				}
			}
			break;
			case FREERDP_SETTINGS_TYPE_UINT64: /* UINT64 */
			{
				UINT64 sval =
				    freerdp_settings_get_uint64(settings, (FreeRDP_Settings_Keys_UInt64)cur->id);
				UINT64 cval =
				    freerdp_settings_get_uint64(other, (FreeRDP_Settings_Keys_UInt64)cur->id);
				if (sval != cval)
				{
					rc = TRUE;
					WLog_Print(log, level, "%s [UINT64]: %" PRIu64 " -> %" PRIu64, cur->str, sval,
					           cval);
				}
			}
			break;
			case FREERDP_SETTINGS_TYPE_INT64: /* INT64 */
			{
				INT64 sval =
				    freerdp_settings_get_int64(settings, (FreeRDP_Settings_Keys_Int64)cur->id);
				INT64 cval =
				    freerdp_settings_get_int64(other, (FreeRDP_Settings_Keys_Int64)cur->id);
				if (sval != cval)
				{
					rc = TRUE;
					WLog_Print(log, level, "%s [INT64]: %" PRId64 " -> %" PRId64, cur->str, sval,
					           cval);
				}
			}
			break;
			case FREERDP_SETTINGS_TYPE_STRING: /* strings */
			{
				const char* sval =
				    freerdp_settings_get_string(settings, (FreeRDP_Settings_Keys_String)cur->id);
				const char* cval =
				    freerdp_settings_get_string(other, (FreeRDP_Settings_Keys_String)cur->id);
				if (sval != cval)
				{
					if (!sval || !cval || (strcmp(sval, cval) != 0))
					{
						rc = TRUE;
						WLog_Print(log, level, "%s [STRING]: '%s' -> '%s'", cur->str, sval, cval);
					}
				}
			}
			break;
			case FREERDP_SETTINGS_TYPE_POINTER: /* pointer */
			{
				const void* sval =
				    freerdp_settings_get_pointer(settings, (FreeRDP_Settings_Keys_Pointer)cur->id);
				const void* cval =
				    freerdp_settings_get_pointer(other, (FreeRDP_Settings_Keys_Pointer)cur->id);
				if (sval != cval)
				{
					if ((sval && !cval) || (!sval && cval))
					{
						rc = TRUE;
						WLog_Print(log, level, "%s [POINTER]: '%p' -> '%p'", cur->str, sval, cval);
					}
				}
			}
			break;
		}
	}
	return rc;
}

void freerdp_settings_dump(wLog* log, DWORD level, const rdpSettings* settings)
{
	WINPR_ASSERT(log);
	WINPR_ASSERT(settings);

	for (size_t x = 0; x < ARRAYSIZE(settings_map); x++)
	{
		const struct settings_str_entry* cur = &settings_map[x];
		switch (cur->type)
		{
			case FREERDP_SETTINGS_TYPE_BOOL: /* bool */
			{
				BOOL sval =
				    freerdp_settings_get_bool(settings, (FreeRDP_Settings_Keys_Bool)cur->id);
				WLog_Print(log, level, "%s [BOOL]: %s", cur->str, sval ? "TRUE" : "FALSE");
			}
			break;
			case FREERDP_SETTINGS_TYPE_UINT16: /* UINT16 */
			{
				UINT16 sval =
				    freerdp_settings_get_uint16(settings, (FreeRDP_Settings_Keys_UInt16)cur->id);
				WLog_Print(log, level, "%s [UINT16]: %" PRIu16, cur->str, sval);
			}
			break;
			case FREERDP_SETTINGS_TYPE_INT16: /* INT16 */
			{
				INT16 sval =
				    freerdp_settings_get_int16(settings, (FreeRDP_Settings_Keys_Int16)cur->id);
				WLog_Print(log, level, "%s [INT16]: %" PRId16, cur->str, sval);
			}
			break;
			case FREERDP_SETTINGS_TYPE_UINT32: /* UINT32 */
			{
				UINT32 sval =
				    freerdp_settings_get_uint32(settings, (FreeRDP_Settings_Keys_UInt32)cur->id);
				WLog_Print(log, level, "%s [UINT32]: %" PRIu32, cur->str, sval);
			}
			break;
			case FREERDP_SETTINGS_TYPE_INT32: /* INT32 */
			{
				INT32 sval =
				    freerdp_settings_get_int32(settings, (FreeRDP_Settings_Keys_Int32)cur->id);
				WLog_Print(log, level, "%s [INT32]: %" PRId32, cur->str, sval);
			}
			break;
			case FREERDP_SETTINGS_TYPE_UINT64: /* UINT64 */
			{
				UINT64 sval =
				    freerdp_settings_get_uint64(settings, (FreeRDP_Settings_Keys_UInt64)cur->id);
				WLog_Print(log, level, "%s [UINT64]: %" PRIu64, cur->str, sval);
			}
			break;
			case FREERDP_SETTINGS_TYPE_INT64: /* INT64 */
			{
				INT64 sval =
				    freerdp_settings_get_int64(settings, (FreeRDP_Settings_Keys_Int64)cur->id);
				WLog_Print(log, level, "%s [INT64]: %" PRId64, cur->str, sval);
			}
			break;
			case FREERDP_SETTINGS_TYPE_STRING: /* strings */
			{
				const char* sval =
				    freerdp_settings_get_string(settings, (FreeRDP_Settings_Keys_String)cur->id);
				WLog_Print(log, level, "%s [STRING]: '%s'", cur->str, sval);
			}
			break;
			case FREERDP_SETTINGS_TYPE_POINTER: /* pointer */
			{
				const void* sval =
				    freerdp_settings_get_pointer(settings, (FreeRDP_Settings_Keys_Pointer)cur->id);
				WLog_Print(log, level, "%s [POINTER]: '%p'", cur->str, sval);
			}
			break;
		}
	}
}

void freerdp_settings_free_keys(rdpSettings* dst, BOOL cleanup)
{
	WINPR_ASSERT(dst);

	for (size_t x = 0; x < ARRAYSIZE(settings_map); x++)
	{
		const struct settings_str_entry* cur = &settings_map[x];
		switch (cur->type)
		{
			case FREERDP_SETTINGS_TYPE_STRING: /* strings */
				(void)freerdp_settings_set_string_copy_(dst, (FreeRDP_Settings_Keys_String)cur->id,
				                                        NULL, 0, cleanup);
				break;
			case FREERDP_SETTINGS_TYPE_POINTER: /* pointer */
				(void)freerdp_settings_set_pointer_len(dst, (FreeRDP_Settings_Keys_Pointer)cur->id,
				                                       NULL, 0);
				break;
		}
	}
}

SSIZE_T freerdp_settings_get_key_for_name(const char* value)
{
	WINPR_ASSERT(value);

	for (size_t x = 0; x < ARRAYSIZE(settings_map); x++)
	{
		const struct settings_str_entry* cur = &settings_map[x];
		if (strcmp(value, cur->str) == 0)
			return cur->id;
	}
	return -1;
}

SSIZE_T freerdp_settings_get_type_for_name(const char* value)
{
	WINPR_ASSERT(value);

	for (size_t x = 0; x < ARRAYSIZE(settings_map); x++)
	{
		const struct settings_str_entry* cur = &settings_map[x];
		if (strcmp(value, cur->str) == 0)
			return cur->type;
	}
	return -1;
}

const char* freerdp_settings_get_type_name_for_key(SSIZE_T key)
{
	const SSIZE_T type = freerdp_settings_get_type_for_key(key);
	return freerdp_settings_get_type_name_for_type(type);
}

const char* freerdp_settings_get_type_name_for_type(SSIZE_T type)
{
	switch (type)
	{
		case FREERDP_SETTINGS_TYPE_BOOL:
			return "FREERDP_SETTINGS_TYPE_BOOL";
		case FREERDP_SETTINGS_TYPE_UINT16:
			return "FREERDP_SETTINGS_TYPE_UINT16";
		case FREERDP_SETTINGS_TYPE_INT16:
			return "FREERDP_SETTINGS_TYPE_INT16";
		case FREERDP_SETTINGS_TYPE_UINT32:
			return "FREERDP_SETTINGS_TYPE_UINT32";
		case FREERDP_SETTINGS_TYPE_INT32:
			return "FREERDP_SETTINGS_TYPE_INT32";
		case FREERDP_SETTINGS_TYPE_UINT64:
			return "FREERDP_SETTINGS_TYPE_UINT64";
		case FREERDP_SETTINGS_TYPE_INT64:
			return "FREERDP_SETTINGS_TYPE_INT64";
		case FREERDP_SETTINGS_TYPE_STRING:
			return "FREERDP_SETTINGS_TYPE_STRING";
		case FREERDP_SETTINGS_TYPE_POINTER:
			return "FREERDP_SETTINGS_TYPE_POINTER";
		default:
			return "FREERDP_SETTINGS_TYPE_UNKNOWN";
	}
}

SSIZE_T freerdp_settings_get_type_for_key(SSIZE_T key)
{
	for (size_t x = 0; x < ARRAYSIZE(settings_map); x++)
	{
		const struct settings_str_entry* cur = &settings_map[x];
		if (cur->id == key)
			return cur->type;
	}
	return -1;
}

const char* freerdp_settings_get_name_for_key(SSIZE_T key)
{
	for (size_t x = 0; x < ARRAYSIZE(settings_map); x++)
	{
		const struct settings_str_entry* cur = &settings_map[x];
		if (cur->id == key)
			return cur->str;
	}
	return NULL;
}

BOOL freerdp_settings_copy_item(rdpSettings* dst, const rdpSettings* src, SSIZE_T id)
{
	WINPR_ASSERT(dst);
	WINPR_ASSERT(src);

	const SSIZE_T key = freerdp_settings_get_type_for_key(id);
	switch (key)
	{
		case FREERDP_SETTINGS_TYPE_BOOL:
		{
			const BOOL val = freerdp_settings_get_bool(src, (FreeRDP_Settings_Keys_Bool)id);
			return freerdp_settings_set_bool(dst, (FreeRDP_Settings_Keys_Bool)id, val);
		}
		case FREERDP_SETTINGS_TYPE_INT16:
		{
			const INT16 val = freerdp_settings_get_int16(src, (FreeRDP_Settings_Keys_Int16)id);
			return freerdp_settings_set_int16(dst, (FreeRDP_Settings_Keys_Int16)id, val);
		}
		case FREERDP_SETTINGS_TYPE_INT32:
		{
			const INT32 val = freerdp_settings_get_int32(src, (FreeRDP_Settings_Keys_Int32)id);
			return freerdp_settings_set_int32(dst, (FreeRDP_Settings_Keys_Int32)id, val);
		}
		case FREERDP_SETTINGS_TYPE_INT64:
		{
			const INT64 val = freerdp_settings_get_int64(src, (FreeRDP_Settings_Keys_Int64)id);
			return freerdp_settings_set_int64(dst, (FreeRDP_Settings_Keys_Int64)id, val);
		}
		case FREERDP_SETTINGS_TYPE_UINT16:
		{
			const UINT16 val = freerdp_settings_get_uint16(src, (FreeRDP_Settings_Keys_UInt16)id);
			return freerdp_settings_set_uint16(dst, (FreeRDP_Settings_Keys_UInt16)id, val);
		}
		case FREERDP_SETTINGS_TYPE_UINT32:
		{
			const UINT32 val = freerdp_settings_get_uint32(src, (FreeRDP_Settings_Keys_UInt32)id);
			return freerdp_settings_set_uint32(dst, (FreeRDP_Settings_Keys_UInt32)id, val);
		}
		case FREERDP_SETTINGS_TYPE_UINT64:
		{
			const UINT64 val = freerdp_settings_get_uint64(src, (FreeRDP_Settings_Keys_UInt64)id);
			return freerdp_settings_set_uint64(dst, (FreeRDP_Settings_Keys_UInt64)id, val);
		}
		case FREERDP_SETTINGS_TYPE_STRING:
		{
			const char* val = freerdp_settings_get_string(src, (FreeRDP_Settings_Keys_String)id);
			return freerdp_settings_set_string(dst, (FreeRDP_Settings_Keys_String)id, val);
		}
		case FREERDP_SETTINGS_TYPE_POINTER:
		{
			const void* val = freerdp_settings_get_pointer(src, (FreeRDP_Settings_Keys_Pointer)id);
			return freerdp_settings_set_pointer(dst, (FreeRDP_Settings_Keys_Pointer)id, val);
		}
		default:
			return FALSE;
	}
}
