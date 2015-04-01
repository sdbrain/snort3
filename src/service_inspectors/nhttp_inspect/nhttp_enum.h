//--------------------------------------------------------------------------
// Copyright (C) 2014-2015 Cisco and/or its affiliates. All rights reserved.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License Version 2 as published
// by the Free Software Foundation.  You may not use, modify or distribute
// this program under any other version of the GNU General Public License.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//--------------------------------------------------------------------------
// nhttp_enum.h author Tom Peters <thopeter@cisco.com>

#ifndef NHTTP_ENUM_H
#define NHTTP_ENUM_H

#include <stdint.h>

namespace NHttpEnums
{
static const int MAXOCTETS = 63780;
static const int DATABLOCKSIZE = 16384;
static const uint32_t NHTTP_GID = 219;

// Field status codes for when no valid value is present in length or integer value. Positive
// values are actual length
// or field value.
typedef enum { STAT_NOSOURCE=-6, STAT_NOTCONFIGURED=-5, STAT_NOTCOMPUTE=-4, STAT_INSUFMEMORY=-3,
               STAT_PROBLEMATIC=-2,
               STAT_NOTPRESENT=-1, STAT_EMPTYSTRING=0, STAT_OTHER=1 } StatusCode;

// Message originator--client or server
typedef enum { SRC__NOTCOMPUTE=-4, SRC_CLIENT=0, SRC_SERVER=1 } SourceId;

// Type of message section
typedef enum { SEC_DISCARD = -10, SEC_CLOSED = -9, SEC_ABORT = -8, SEC__NOTCOMPUTE=-4,
               SEC__NOTPRESENT=-1,
               SEC_REQUEST = 2, SEC_STATUS, SEC_HEADER, SEC_BODY, SEC_CHUNK,
               SEC_TRAILER } SectionType;

// Result of scanning by splitter
typedef enum { SCAN_NOTFOUND, SCAN_FOUND, SCAN_DISCARD, SCAN_DISCARD_CONTINUE,
               SCAN_ABORT } ScanResult;

// Result of processing a message section--what needs to happen next
typedef enum { RES_INSPECT, RES_IGNORE, RES_AGGREGATE } ProcessResult;

// List of possible HTTP versions. Version 0.9 omitted because 0.9 predates creation of the
// HTTP/X.Y token. There would
// never be a message with "HTTP/0.9"
typedef enum { VERS__NOSOURCE=-6, VERS__NOTCOMPUTE=-4, VERS__PROBLEMATIC=-2, VERS__NOTPRESENT=-1,
               VERS__OTHER=1,
               VERS_1_0, VERS_1_1, VERS_2_0 } VersionId;

// Every request method we have ever heard of
typedef enum { METH__NOSOURCE=-6, METH__NOTCOMPUTE=-4, METH__INSUFMEMORY=-3, METH__PROBLEMATIC=-2,
               METH__NOTPRESENT=-1,
               METH__OTHER=1, METH_OPTIONS, METH_GET, METH_HEAD, METH_POST, METH_PUT, METH_DELETE,
               METH_TRACE, METH_CONNECT,
               METH_PROPFIND, METH_PROPPATCH, METH_MKCOL, METH_COPY, METH_MOVE, METH_LOCK,
               METH_UNLOCK, METH_VERSION_CONTROL,
               METH_REPORT, METH_CHECKOUT, METH_CHECKIN, METH_UNCHECKOUT, METH_MKWORKSPACE,
               METH_UPDATE, METH_LABEL, METH_MERGE,
               METH_BASELINE_CONTROL, METH_MKACTIVITY, METH_ORDERPATCH, METH_ACL, METH_PATCH,
               METH_SEARCH, METH_BCOPY, METH_BDELETE,
               METH_BMOVE, METH_BPROPFIND, METH_BPROPPATCH, METH_NOTIFY, METH_POLL, METH_SUBSCRIBE,
               METH_UNSUBSCRIBE,
               METH_X_MS_ENUMATTS, METH_BIND, METH_LINK, METH_MKCALENDAR, METH_MKREDIRECTREF,
               METH_REBIND, METH_UNBIND, METH_UNLINK,
               METH_UPDATEREDIRECTREF } MethodId;

// URI formats
typedef enum { URI__NOSOURCE=-6, URI__NOTCOMPUTE=-4, URI__PROBLEMATIC=-2, URI_ASTERISK = 2,
               URI_AUTHORITY, URI_ABSPATH,
               URI_ABSOLUTE } UriType;

// URI schemes
typedef enum { SCH__NOSOURCE=-6, SCH__NOTCOMPUTE=-4, SCH__INSUFMEMORY=-3, SCH__NOTPRESENT=-1,
               SCH_OTHER = 1, SCH_HTTP,
               SCH_HTTPS, SCH_FTP, SCH_GOPHER, SCH_FILE } SchemeId;

// Every header we have ever heard of
typedef enum { HEAD__NOTCOMPUTE=-4, HEAD__INSUFMEMORY=-3, HEAD__PROBLEMATIC=-2, HEAD__NOTPRESENT=
                   -1, HEAD__OTHER=1,
               HEAD_CACHE_CONTROL, HEAD_CONNECTION, HEAD_DATE, HEAD_PRAGMA, HEAD_TRAILER,
               HEAD_COOKIE, HEAD_SET_COOKIE,
               HEAD_TRANSFER_ENCODING, HEAD_UPGRADE, HEAD_VIA, HEAD_WARNING, HEAD_ACCEPT,
               HEAD_ACCEPT_CHARSET, HEAD_ACCEPT_ENCODING,
               HEAD_ACCEPT_LANGUAGE, HEAD_AUTHORIZATION, HEAD_EXPECT, HEAD_FROM, HEAD_HOST,
               HEAD_IF_MATCH, HEAD_IF_MODIFIED_SINCE,
               HEAD_IF_NONE_MATCH, HEAD_IF_RANGE, HEAD_IF_UNMODIFIED_SINCE, HEAD_MAX_FORWARDS,
               HEAD_PROXY_AUTHORIZATION, HEAD_RANGE,
               HEAD_REFERER, HEAD_TE, HEAD_USER_AGENT, HEAD_ACCEPT_RANGES, HEAD_AGE, HEAD_ETAG,
               HEAD_LOCATION, HEAD_PROXY_AUTHENTICATE,
               HEAD_RETRY_AFTER, HEAD_SERVER, HEAD_VARY, HEAD_WWW_AUTHENTICATE, HEAD_ALLOW,
               HEAD_CONTENT_ENCODING, HEAD_CONTENT_LANGUAGE,
               HEAD_CONTENT_LENGTH, HEAD_CONTENT_LOCATION, HEAD_CONTENT_MD5, HEAD_CONTENT_RANGE,
               HEAD_CONTENT_TYPE, HEAD_EXPIRES,
               HEAD_LAST_MODIFIED, HEAD_X_FORWARDED_FOR, HEAD_TRUE_CLIENT_IP,
               HEAD__MAXVALUE } HeaderId;

// All the infractions we might find while parsing and analyzing a message
typedef enum
{
    INF_TRUNCATED = 0,
    INF_HEADTOOLONG,
    INF_BADREQLINE,
    INF_BADSTATLINE,
    INF_TOOMANYHEADERS,
    INF_BADHEADER,
    INF_BADSTATCODE,
    INF_UNKNOWNVERSION,
    INF_BADVERSION,
    INF_NOSCRATCH,
    INF_BADHEADERREPS,
    INF_BADHEADERDATA,
    INF_FIXIT_L_UNUSED,
    INF_BADCHUNKSIZE,
    INF_BADPHRASE,
    INF_BADURI,
    INF_BADPORT,
    INF_URINEEDNORM,
    INF_URIPERCENTNORMAL,
    INF_URIPERCENTASCII,
    INF_URIPERCENTUTF8,
    INF_URIPERCENTUCODE,
    INF_URIPERCENTOTHER,
    INF_URIBADCHAR,
    INF_URI8BITCHAR,
    INF_URIMULTISLASH,
    INF_URIBACKSLASH,
    INF_URISLASHDOT,
    INF_URISLASHDOTDOT,
    INF_URIROOTTRAV,
    INF_TOOMUCHLEADINGWS,
    INF_ENDLESSHEADER,
    INF_LFWITHOUTCR,
} Infraction;

// Formats for output from a header normalization function
typedef enum { NORM_NULL, NORM_FIELD, NORM_INT64, NORM_ENUM64, NORM_ENUM64LIST } NormFormat;

// Types of character for URI scanning
typedef enum { CHAR_NORMAL=2, CHAR_PERCENT, CHAR_PATH, CHAR_INVALID, CHAR_EIGHTBIT } CharAction;

// Transfer codings
typedef enum { TRANSCODE__OTHER=1, TRANSCODE_CHUNKED, TRANSCODE_IDENTITY, TRANSCODE_GZIP,
               TRANSCODE_COMPRESS,
               TRANSCODE_DEFLATE } Transcoding;

typedef enum
{   // FIXIT-L limit 64 before code changes required
    EVENT_ASCII = 1,
    EVENT_DOUBLE_DECODE,
    EVENT_U_ENCODE,
    EVENT_BARE_BYTE,
    EVENT_OBSOLETE_1,
    EVENT_UTF_8,
    EVENT_IIS_UNICODE,
    EVENT_MULTI_SLASH,
    EVENT_IIS_BACKSLASH,
    EVENT_SELF_DIR_TRAV,
    EVENT_DIR_TRAV,
    EVENT_APACHE_WS,
    EVENT_IIS_DELIMITER,
    EVENT_NON_RFC_CHAR,
    EVENT_OVERSIZE_DIR,
    EVENT_LARGE_CHUNK,
    EVENT_PROXY_USE,
    EVENT_WEBROOT_DIR,
    EVENT_LONG_HDR,
    EVENT_MAX_HEADERS,
    EVENT_MULTIPLE_CONTLEN,
    EVENT_CHUNK_SIZE_MISMATCH,
    EVENT_INVALID_TRUEIP,
    EVENT_MULTIPLE_HOST_HDRS,
    EVENT_LONG_HOSTNAME,
    EVENT_EXCEEDS_SPACES,
    EVENT_CONSECUTIVE_SMALL_CHUNKS,
    EVENT_UNBOUNDED_POST,
    EVENT_MULTIPLE_TRUEIP_IN_SESSION,
    EVENT_BOTH_TRUEIP_XFF_HDRS,
    EVENT_UNKNOWN_METHOD,
    EVENT_SIMPLE_REQUEST,
    EVENT_UNESCAPED_SPACE_URI,
    EVENT_PIPELINE_MAX,
    EVENT_ANOM_SERVER,
    EVENT_INVALID_STATCODE,
    EVENT_NO_CONTLEN,
    EVENT_UTF_NORM_FAIL,
    EVENT_UTF7,
    EVENT_DECOMPR_FAILED,
    EVENT_CONSECUTIVE_SMALL_CHUNKS_S,
    EVENT_MSG_SIZE_EXCEPTION,
    EVENT_JS_OBFUSCATION_EXCD,
    EVENT_JS_EXCESS_WS,
    EVENT_MIXED_ENCODINGS,
    EVENT_SWF_ZLIB_FAILURE,
    EVENT_SWF_LZMA_FAILURE,
    EVENT_PDF_DEFL_FAILURE,
    EVENT_PDF_UNSUP_COMP_TYPE,
    EVENT_PDF_CASC_COMP,
    EVENT_PDF_PARSE_FAILURE,
    EVENT_LOSS_OF_SYNC,
    EVENT_MAXVALUE
} EventSid;

extern const int8_t as_hex[256];
} // end namespace NHttpEnums

#endif

