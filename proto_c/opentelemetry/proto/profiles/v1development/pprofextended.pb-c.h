/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: opentelemetry/proto/profiles/v1development/pprofextended.proto */

#ifndef PROTOBUF_C_opentelemetry_2fproto_2fprofiles_2fv1development_2fpprofextended_2eproto__INCLUDED
#define PROTOBUF_C_opentelemetry_2fproto_2fprofiles_2fv1development_2fpprofextended_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "opentelemetry/proto/common/v1/common.pb-c.h"

typedef struct Opentelemetry__Proto__Profiles__V1development__Profile Opentelemetry__Proto__Profiles__V1development__Profile;
typedef struct Opentelemetry__Proto__Profiles__V1development__AttributeUnit Opentelemetry__Proto__Profiles__V1development__AttributeUnit;
typedef struct Opentelemetry__Proto__Profiles__V1development__Link Opentelemetry__Proto__Profiles__V1development__Link;
typedef struct Opentelemetry__Proto__Profiles__V1development__ValueType Opentelemetry__Proto__Profiles__V1development__ValueType;
typedef struct Opentelemetry__Proto__Profiles__V1development__Sample Opentelemetry__Proto__Profiles__V1development__Sample;
typedef struct Opentelemetry__Proto__Profiles__V1development__Label Opentelemetry__Proto__Profiles__V1development__Label;
typedef struct Opentelemetry__Proto__Profiles__V1development__Mapping Opentelemetry__Proto__Profiles__V1development__Mapping;
typedef struct Opentelemetry__Proto__Profiles__V1development__Location Opentelemetry__Proto__Profiles__V1development__Location;
typedef struct Opentelemetry__Proto__Profiles__V1development__Line Opentelemetry__Proto__Profiles__V1development__Line;
typedef struct Opentelemetry__Proto__Profiles__V1development__Function Opentelemetry__Proto__Profiles__V1development__Function;


/* --- enums --- */

/*
 * Specifies the method of aggregating metric values, either DELTA (change since last report)
 * or CUMULATIVE (total since a fixed start time).
 */
typedef enum _Opentelemetry__Proto__Profiles__V1development__AggregationTemporality {
  /*
   * UNSPECIFIED is the default AggregationTemporality, it MUST not be used. 
   */
  OPENTELEMETRY__PROTO__PROFILES__V1DEVELOPMENT__AGGREGATION_TEMPORALITY__AGGREGATION_TEMPORALITY_UNSPECIFIED = 0,
  /*
   ** DELTA is an AggregationTemporality for a profiler which reports
   *changes since last report time. Successive metrics contain aggregation of
   *values from continuous and non-overlapping intervals.
   *The values for a DELTA metric are based only on the time interval
   *associated with one measurement cycle. There is no dependency on
   *previous measurements like is the case for CUMULATIVE metrics.
   *For example, consider a system measuring the number of requests that
   *it receives and reports the sum of these requests every second as a
   *DELTA metric:
   *1. The system starts receiving at time=t_0.
   *2. A request is received, the system measures 1 request.
   *3. A request is received, the system measures 1 request.
   *4. A request is received, the system measures 1 request.
   *5. The 1 second collection cycle ends. A metric is exported for the
   *number of requests received over the interval of time t_0 to
   *t_0+1 with a value of 3.
   *6. A request is received, the system measures 1 request.
   *7. A request is received, the system measures 1 request.
   *8. The 1 second collection cycle ends. A metric is exported for the
   *number of requests received over the interval of time t_0+1 to
   *t_0+2 with a value of 2. 
   */
  OPENTELEMETRY__PROTO__PROFILES__V1DEVELOPMENT__AGGREGATION_TEMPORALITY__AGGREGATION_TEMPORALITY_DELTA = 1,
  /*
   ** CUMULATIVE is an AggregationTemporality for a profiler which
   *reports changes since a fixed start time. This means that current values
   *of a CUMULATIVE metric depend on all previous measurements since the
   *start time. Because of this, the sender is required to retain this state
   *in some form. If this state is lost or invalidated, the CUMULATIVE metric
   *values MUST be reset and a new fixed start time following the last
   *reported measurement time sent MUST be used.
   *For example, consider a system measuring the number of requests that
   *it receives and reports the sum of these requests every second as a
   *CUMULATIVE metric:
   *1. The system starts receiving at time=t_0.
   *2. A request is received, the system measures 1 request.
   *3. A request is received, the system measures 1 request.
   *4. A request is received, the system measures 1 request.
   *5. The 1 second collection cycle ends. A metric is exported for the
   *number of requests received over the interval of time t_0 to
   *t_0+1 with a value of 3.
   *6. A request is received, the system measures 1 request.
   *7. A request is received, the system measures 1 request.
   *8. The 1 second collection cycle ends. A metric is exported for the
   *number of requests received over the interval of time t_0 to
   *t_0+2 with a value of 5.
   *9. The system experiences a fault and loses state.
   *10. The system recovers and resumes receiving at time=t_1.
   *11. A request is received, the system measures 1 request.
   *12. The 1 second collection cycle ends. A metric is exported for the
   *number of requests received over the interval of time t_1 to
   *t_1+1 with a value of 1.
   *Note: Even though, when reporting changes since last report time, using
   *CUMULATIVE is valid, it is not recommended. 
   */
  OPENTELEMETRY__PROTO__PROFILES__V1DEVELOPMENT__AGGREGATION_TEMPORALITY__AGGREGATION_TEMPORALITY_CUMULATIVE = 2
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(OPENTELEMETRY__PROTO__PROFILES__V1DEVELOPMENT__AGGREGATION_TEMPORALITY)
} Opentelemetry__Proto__Profiles__V1development__AggregationTemporality;

/* --- messages --- */

/*
 * Represents a complete profile, including sample types, samples,
 * mappings to binaries, locations, functions, string table, and additional metadata.
 */
struct  Opentelemetry__Proto__Profiles__V1development__Profile
{
  ProtobufCMessage base;
  /*
   * A description of the samples associated with each Sample.value.
   * For a cpu profile this might be:
   *   [["cpu","nanoseconds"]] or [["wall","seconds"]] or [["syscall","count"]]
   * For a heap profile, this might be:
   *   [["allocations","count"], ["space","bytes"]],
   * If one of the values represents the number of events represented
   * by the sample, by convention it should be at index 0 and use
   * sample_type.unit == "count".
   */
  size_t n_sample_type;
  Opentelemetry__Proto__Profiles__V1development__ValueType **sample_type;
  /*
   * The set of samples recorded in this profile.
   */
  size_t n_sample;
  Opentelemetry__Proto__Profiles__V1development__Sample **sample;
  /*
   * Mapping from address ranges to the image/binary/library mapped
   * into that address range.  mapping[0] will be the main binary.
   * If multiple binaries contribute to the Profile and no main
   * binary can be identified, mapping[0] has no special meaning.
   */
  size_t n_mapping;
  Opentelemetry__Proto__Profiles__V1development__Mapping **mapping;
  /*
   * Locations referenced by samples via location_indices.
   */
  size_t n_location;
  Opentelemetry__Proto__Profiles__V1development__Location **location;
  /*
   * Array of locations referenced by samples.
   */
  size_t n_location_indices;
  int64_t *location_indices;
  /*
   * Functions referenced by locations.
   */
  size_t n_function;
  Opentelemetry__Proto__Profiles__V1development__Function **function;
  /*
   * Lookup table for attributes.
   */
  size_t n_attribute_table;
  Opentelemetry__Proto__Common__V1__KeyValue **attribute_table;
  /*
   * Represents a mapping between Attribute Keys and Units.
   */
  size_t n_attribute_units;
  Opentelemetry__Proto__Profiles__V1development__AttributeUnit **attribute_units;
  /*
   * Lookup table for links.
   */
  size_t n_link_table;
  Opentelemetry__Proto__Profiles__V1development__Link **link_table;
  /*
   * A common table for strings referenced by various messages.
   * string_table[0] must always be "".
   */
  size_t n_string_table;
  char **string_table;
  /*
   * frames with Function.function_name fully matching the following
   * regexp will be dropped from the samples, along with their successors.
   */
  /*
   * Index into string table.
   */
  int64_t drop_frames;
  /*
   * frames with Function.function_name fully matching the following
   * regexp will be kept, even if it matches drop_frames.
   */
  /*
   * Index into string table.
   */
  int64_t keep_frames;
  /*
   * Time of collection (UTC) represented as nanoseconds past the epoch.
   */
  int64_t time_nanos;
  /*
   * Duration of the profile, if a duration makes sense.
   */
  int64_t duration_nanos;
  /*
   * The kind of events between sampled occurrences.
   * e.g [ "cpu","cycles" ] or [ "heap","bytes" ]
   */
  Opentelemetry__Proto__Profiles__V1development__ValueType *period_type;
  /*
   * The number of events between sampled occurrences.
   */
  int64_t period;
  /*
   * Free-form text associated with the profile. The text is displayed as is
   * to the user by the tools that read profiles (e.g. by pprof). This field
   * should not be used to store any machine-readable information, it is only
   * for human-friendly content. The profile must stay functional if this field
   * is cleaned.
   */
  /*
   * Indices into string table.
   */
  size_t n_comment;
  int64_t *comment;
  /*
   * Index into the string table of the type of the preferred sample
   * value. If unset, clients should default to the last sample value.
   */
  int64_t default_sample_type;
};
#define OPENTELEMETRY__PROTO__PROFILES__V1DEVELOPMENT__PROFILE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__profiles__v1development__profile__descriptor) \
    , 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0, 0, 0, 0, NULL, 0, 0,NULL, 0 }


/*
 * Represents a mapping between Attribute Keys and Units.
 */
struct  Opentelemetry__Proto__Profiles__V1development__AttributeUnit
{
  ProtobufCMessage base;
  /*
   * Index into string table.
   */
  int64_t attribute_key;
  /*
   * Index into string table.
   */
  int64_t unit;
};
#define OPENTELEMETRY__PROTO__PROFILES__V1DEVELOPMENT__ATTRIBUTE_UNIT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__profiles__v1development__attribute_unit__descriptor) \
    , 0, 0 }


/*
 * A pointer from a profile Sample to a trace Span.
 * Connects a profile sample to a trace span, identified by unique trace and span IDs.
 */
struct  Opentelemetry__Proto__Profiles__V1development__Link
{
  ProtobufCMessage base;
  /*
   * A unique identifier of a trace that this linked span is part of. The ID is a
   * 16-byte array.
   */
  ProtobufCBinaryData trace_id;
  /*
   * A unique identifier for the linked span. The ID is an 8-byte array.
   */
  ProtobufCBinaryData span_id;
};
#define OPENTELEMETRY__PROTO__PROFILES__V1DEVELOPMENT__LINK__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__profiles__v1development__link__descriptor) \
    , {0,NULL}, {0,NULL} }


/*
 * ValueType describes the type and units of a value, with an optional aggregation temporality.
 */
struct  Opentelemetry__Proto__Profiles__V1development__ValueType
{
  ProtobufCMessage base;
  /*
   * Index into string table.
   */
  int64_t type;
  /*
   * Index into string table.
   */
  int64_t unit;
  Opentelemetry__Proto__Profiles__V1development__AggregationTemporality aggregation_temporality;
};
#define OPENTELEMETRY__PROTO__PROFILES__V1DEVELOPMENT__VALUE_TYPE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__profiles__v1development__value_type__descriptor) \
    , 0, 0, OPENTELEMETRY__PROTO__PROFILES__V1DEVELOPMENT__AGGREGATION_TEMPORALITY__AGGREGATION_TEMPORALITY_UNSPECIFIED }


/*
 * Each Sample records values encountered in some program
 * context. The program context is typically a stack trace, perhaps
 * augmented with auxiliary information like the thread-id, some
 * indicator of a higher level request being handled etc.
 */
struct  Opentelemetry__Proto__Profiles__V1development__Sample
{
  ProtobufCMessage base;
  /*
   * The indices recorded here correspond to locations in Profile.location.
   * The leaf is at location_index[0]. [deprecated, superseded by locations_start_index / locations_length]
   */
  size_t n_location_index;
  uint64_t *location_index;
  /*
   * locations_start_index along with locations_length refers to to a slice of locations in Profile.location.
   * Supersedes location_index.
   */
  uint64_t locations_start_index;
  /*
   * locations_length along with locations_start_index refers to a slice of locations in Profile.location.
   * Supersedes location_index.
   */
  uint64_t locations_length;
  /*
   * The type and unit of each value is defined by the corresponding
   * entry in Profile.sample_type. All samples must have the same
   * number of values, the same as the length of Profile.sample_type.
   * When aggregating multiple samples into a single sample, the
   * result has a list of values that is the element-wise sum of the
   * lists of the originals.
   */
  size_t n_value;
  int64_t *value;
  /*
   * References to attributes in Profile.attribute_table. [optional]
   */
  size_t n_attributes;
  uint64_t *attributes;
  /*
   * Reference to link in Profile.link_table. [optional]
   */
  uint64_t link;
  /*
   * Timestamps associated with Sample represented in nanoseconds. These timestamps are expected
   * to fall within the Profile's time range. [optional]
   */
  size_t n_timestamps_unix_nano;
  uint64_t *timestamps_unix_nano;
};
#define OPENTELEMETRY__PROTO__PROFILES__V1DEVELOPMENT__SAMPLE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__profiles__v1development__sample__descriptor) \
    , 0,NULL, 0, 0, 0,NULL, 0,NULL, 0, 0,NULL }


/*
 * Provides additional context for a sample,
 * such as thread ID or allocation size, with optional units. [deprecated]
 */
struct  Opentelemetry__Proto__Profiles__V1development__Label
{
  ProtobufCMessage base;
  /*
   * Index into string table
   */
  int64_t key;
  /*
   * At most one of the following must be present
   */
  /*
   * Index into string table
   */
  int64_t str;
  int64_t num;
  /*
   * Should only be present when num is present.
   * Specifies the units of num.
   * Use arbitrary string (for example, "requests") as a custom count unit.
   * If no unit is specified, consumer may apply heuristic to deduce the unit.
   * Consumers may also  interpret units like "bytes" and "kilobytes" as memory
   * units and units like "seconds" and "nanoseconds" as time units,
   * and apply appropriate unit conversions to these.
   */
  /*
   * Index into string table
   */
  int64_t num_unit;
};
#define OPENTELEMETRY__PROTO__PROFILES__V1DEVELOPMENT__LABEL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__profiles__v1development__label__descriptor) \
    , 0, 0, 0, 0 }


/*
 * Describes the mapping of a binary in memory, including its address range,
 * file offset, and metadata like build ID
 */
struct  Opentelemetry__Proto__Profiles__V1development__Mapping
{
  ProtobufCMessage base;
  /*
   * Unique nonzero id for the mapping. [deprecated]
   */
  uint64_t id;
  /*
   * Address at which the binary (or DLL) is loaded into memory.
   */
  uint64_t memory_start;
  /*
   * The limit of the address range occupied by this mapping.
   */
  uint64_t memory_limit;
  /*
   * Offset in the binary that corresponds to the first mapped address.
   */
  uint64_t file_offset;
  /*
   * The object this entry is loaded from.  This can be a filename on
   * disk for the main binary and shared libraries, or virtual
   * abstractions like "[vdso]".
   */
  /*
   * Index into string table
   */
  int64_t filename;
  /*
   * References to attributes in Profile.attribute_table. [optional]
   */
  size_t n_attributes;
  uint64_t *attributes;
  /*
   * The following fields indicate the resolution of symbolic info.
   */
  protobuf_c_boolean has_functions;
  protobuf_c_boolean has_filenames;
  protobuf_c_boolean has_line_numbers;
  protobuf_c_boolean has_inline_frames;
};
#define OPENTELEMETRY__PROTO__PROFILES__V1DEVELOPMENT__MAPPING__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__profiles__v1development__mapping__descriptor) \
    , 0, 0, 0, 0, 0, 0,NULL, 0, 0, 0, 0 }


/*
 * Describes function and line table debug information.
 */
struct  Opentelemetry__Proto__Profiles__V1development__Location
{
  ProtobufCMessage base;
  /*
   * Unique nonzero id for the location.  A profile could use
   * instruction addresses or any integer sequence as ids. [deprecated]
   */
  uint64_t id;
  /*
   * The index of the corresponding profile.Mapping for this location.
   * It can be unset if the mapping is unknown or not applicable for
   * this profile type.
   */
  uint64_t mapping_index;
  /*
   * The instruction address for this location, if available.  It
   * should be within [Mapping.memory_start...Mapping.memory_limit]
   * for the corresponding mapping. A non-leaf address may be in the
   * middle of a call instruction. It is up to display tools to find
   * the beginning of the instruction if necessary.
   */
  uint64_t address;
  /*
   * Multiple line indicates this location has inlined functions,
   * where the last entry represents the caller into which the
   * preceding entries were inlined.
   * E.g., if memcpy() is inlined into printf:
   *    line[0].function_name == "memcpy"
   *    line[1].function_name == "printf"
   */
  size_t n_line;
  Opentelemetry__Proto__Profiles__V1development__Line **line;
  /*
   * Provides an indication that multiple symbols map to this location's
   * address, for example due to identical code folding by the linker. In that
   * case the line information above represents one of the multiple
   * symbols. This field must be recomputed when the symbolization state of the
   * profile changes.
   */
  protobuf_c_boolean is_folded;
  /*
   * References to attributes in Profile.attribute_table. [optional]
   */
  size_t n_attributes;
  uint64_t *attributes;
};
#define OPENTELEMETRY__PROTO__PROFILES__V1DEVELOPMENT__LOCATION__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__profiles__v1development__location__descriptor) \
    , 0, 0, 0, 0,NULL, 0, 0,NULL }


/*
 * Details a specific line in a source code, linked to a function.
 */
struct  Opentelemetry__Proto__Profiles__V1development__Line
{
  ProtobufCMessage base;
  /*
   * The index of the corresponding profile.Function for this line.
   */
  uint64_t function_index;
  /*
   * Line number in source code.
   */
  int64_t line;
  /*
   * Column number in source code.
   */
  int64_t column;
};
#define OPENTELEMETRY__PROTO__PROFILES__V1DEVELOPMENT__LINE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__profiles__v1development__line__descriptor) \
    , 0, 0, 0 }


/*
 * Describes a function, including its human-readable name, system name,
 * source file, and starting line number in the source.
 */
struct  Opentelemetry__Proto__Profiles__V1development__Function
{
  ProtobufCMessage base;
  /*
   * Unique nonzero id for the function. [deprecated]
   */
  uint64_t id;
  /*
   * Name of the function, in human-readable form if available.
   */
  /*
   * Index into string table
   */
  int64_t name;
  /*
   * Name of the function, as identified by the system.
   * For instance, it can be a C++ mangled name.
   */
  /*
   * Index into string table
   */
  int64_t system_name;
  /*
   * Source file containing the function.
   */
  /*
   * Index into string table
   */
  int64_t filename;
  /*
   * Line number in source file.
   */
  int64_t start_line;
};
#define OPENTELEMETRY__PROTO__PROFILES__V1DEVELOPMENT__FUNCTION__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__profiles__v1development__function__descriptor) \
    , 0, 0, 0, 0, 0 }


/* Opentelemetry__Proto__Profiles__V1development__Profile methods */
void   opentelemetry__proto__profiles__v1development__profile__init
                     (Opentelemetry__Proto__Profiles__V1development__Profile         *message);
size_t opentelemetry__proto__profiles__v1development__profile__get_packed_size
                     (const Opentelemetry__Proto__Profiles__V1development__Profile   *message);
size_t opentelemetry__proto__profiles__v1development__profile__pack
                     (const Opentelemetry__Proto__Profiles__V1development__Profile   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__profiles__v1development__profile__pack_to_buffer
                     (const Opentelemetry__Proto__Profiles__V1development__Profile   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Profiles__V1development__Profile *
       opentelemetry__proto__profiles__v1development__profile__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__profiles__v1development__profile__free_unpacked
                     (Opentelemetry__Proto__Profiles__V1development__Profile *message,
                      ProtobufCAllocator *allocator);
/* Opentelemetry__Proto__Profiles__V1development__AttributeUnit methods */
void   opentelemetry__proto__profiles__v1development__attribute_unit__init
                     (Opentelemetry__Proto__Profiles__V1development__AttributeUnit         *message);
size_t opentelemetry__proto__profiles__v1development__attribute_unit__get_packed_size
                     (const Opentelemetry__Proto__Profiles__V1development__AttributeUnit   *message);
size_t opentelemetry__proto__profiles__v1development__attribute_unit__pack
                     (const Opentelemetry__Proto__Profiles__V1development__AttributeUnit   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__profiles__v1development__attribute_unit__pack_to_buffer
                     (const Opentelemetry__Proto__Profiles__V1development__AttributeUnit   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Profiles__V1development__AttributeUnit *
       opentelemetry__proto__profiles__v1development__attribute_unit__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__profiles__v1development__attribute_unit__free_unpacked
                     (Opentelemetry__Proto__Profiles__V1development__AttributeUnit *message,
                      ProtobufCAllocator *allocator);
/* Opentelemetry__Proto__Profiles__V1development__Link methods */
void   opentelemetry__proto__profiles__v1development__link__init
                     (Opentelemetry__Proto__Profiles__V1development__Link         *message);
size_t opentelemetry__proto__profiles__v1development__link__get_packed_size
                     (const Opentelemetry__Proto__Profiles__V1development__Link   *message);
size_t opentelemetry__proto__profiles__v1development__link__pack
                     (const Opentelemetry__Proto__Profiles__V1development__Link   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__profiles__v1development__link__pack_to_buffer
                     (const Opentelemetry__Proto__Profiles__V1development__Link   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Profiles__V1development__Link *
       opentelemetry__proto__profiles__v1development__link__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__profiles__v1development__link__free_unpacked
                     (Opentelemetry__Proto__Profiles__V1development__Link *message,
                      ProtobufCAllocator *allocator);
/* Opentelemetry__Proto__Profiles__V1development__ValueType methods */
void   opentelemetry__proto__profiles__v1development__value_type__init
                     (Opentelemetry__Proto__Profiles__V1development__ValueType         *message);
size_t opentelemetry__proto__profiles__v1development__value_type__get_packed_size
                     (const Opentelemetry__Proto__Profiles__V1development__ValueType   *message);
size_t opentelemetry__proto__profiles__v1development__value_type__pack
                     (const Opentelemetry__Proto__Profiles__V1development__ValueType   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__profiles__v1development__value_type__pack_to_buffer
                     (const Opentelemetry__Proto__Profiles__V1development__ValueType   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Profiles__V1development__ValueType *
       opentelemetry__proto__profiles__v1development__value_type__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__profiles__v1development__value_type__free_unpacked
                     (Opentelemetry__Proto__Profiles__V1development__ValueType *message,
                      ProtobufCAllocator *allocator);
/* Opentelemetry__Proto__Profiles__V1development__Sample methods */
void   opentelemetry__proto__profiles__v1development__sample__init
                     (Opentelemetry__Proto__Profiles__V1development__Sample         *message);
size_t opentelemetry__proto__profiles__v1development__sample__get_packed_size
                     (const Opentelemetry__Proto__Profiles__V1development__Sample   *message);
size_t opentelemetry__proto__profiles__v1development__sample__pack
                     (const Opentelemetry__Proto__Profiles__V1development__Sample   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__profiles__v1development__sample__pack_to_buffer
                     (const Opentelemetry__Proto__Profiles__V1development__Sample   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Profiles__V1development__Sample *
       opentelemetry__proto__profiles__v1development__sample__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__profiles__v1development__sample__free_unpacked
                     (Opentelemetry__Proto__Profiles__V1development__Sample *message,
                      ProtobufCAllocator *allocator);
/* Opentelemetry__Proto__Profiles__V1development__Label methods */
void   opentelemetry__proto__profiles__v1development__label__init
                     (Opentelemetry__Proto__Profiles__V1development__Label         *message);
size_t opentelemetry__proto__profiles__v1development__label__get_packed_size
                     (const Opentelemetry__Proto__Profiles__V1development__Label   *message);
size_t opentelemetry__proto__profiles__v1development__label__pack
                     (const Opentelemetry__Proto__Profiles__V1development__Label   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__profiles__v1development__label__pack_to_buffer
                     (const Opentelemetry__Proto__Profiles__V1development__Label   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Profiles__V1development__Label *
       opentelemetry__proto__profiles__v1development__label__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__profiles__v1development__label__free_unpacked
                     (Opentelemetry__Proto__Profiles__V1development__Label *message,
                      ProtobufCAllocator *allocator);
/* Opentelemetry__Proto__Profiles__V1development__Mapping methods */
void   opentelemetry__proto__profiles__v1development__mapping__init
                     (Opentelemetry__Proto__Profiles__V1development__Mapping         *message);
size_t opentelemetry__proto__profiles__v1development__mapping__get_packed_size
                     (const Opentelemetry__Proto__Profiles__V1development__Mapping   *message);
size_t opentelemetry__proto__profiles__v1development__mapping__pack
                     (const Opentelemetry__Proto__Profiles__V1development__Mapping   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__profiles__v1development__mapping__pack_to_buffer
                     (const Opentelemetry__Proto__Profiles__V1development__Mapping   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Profiles__V1development__Mapping *
       opentelemetry__proto__profiles__v1development__mapping__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__profiles__v1development__mapping__free_unpacked
                     (Opentelemetry__Proto__Profiles__V1development__Mapping *message,
                      ProtobufCAllocator *allocator);
/* Opentelemetry__Proto__Profiles__V1development__Location methods */
void   opentelemetry__proto__profiles__v1development__location__init
                     (Opentelemetry__Proto__Profiles__V1development__Location         *message);
size_t opentelemetry__proto__profiles__v1development__location__get_packed_size
                     (const Opentelemetry__Proto__Profiles__V1development__Location   *message);
size_t opentelemetry__proto__profiles__v1development__location__pack
                     (const Opentelemetry__Proto__Profiles__V1development__Location   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__profiles__v1development__location__pack_to_buffer
                     (const Opentelemetry__Proto__Profiles__V1development__Location   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Profiles__V1development__Location *
       opentelemetry__proto__profiles__v1development__location__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__profiles__v1development__location__free_unpacked
                     (Opentelemetry__Proto__Profiles__V1development__Location *message,
                      ProtobufCAllocator *allocator);
/* Opentelemetry__Proto__Profiles__V1development__Line methods */
void   opentelemetry__proto__profiles__v1development__line__init
                     (Opentelemetry__Proto__Profiles__V1development__Line         *message);
size_t opentelemetry__proto__profiles__v1development__line__get_packed_size
                     (const Opentelemetry__Proto__Profiles__V1development__Line   *message);
size_t opentelemetry__proto__profiles__v1development__line__pack
                     (const Opentelemetry__Proto__Profiles__V1development__Line   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__profiles__v1development__line__pack_to_buffer
                     (const Opentelemetry__Proto__Profiles__V1development__Line   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Profiles__V1development__Line *
       opentelemetry__proto__profiles__v1development__line__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__profiles__v1development__line__free_unpacked
                     (Opentelemetry__Proto__Profiles__V1development__Line *message,
                      ProtobufCAllocator *allocator);
/* Opentelemetry__Proto__Profiles__V1development__Function methods */
void   opentelemetry__proto__profiles__v1development__function__init
                     (Opentelemetry__Proto__Profiles__V1development__Function         *message);
size_t opentelemetry__proto__profiles__v1development__function__get_packed_size
                     (const Opentelemetry__Proto__Profiles__V1development__Function   *message);
size_t opentelemetry__proto__profiles__v1development__function__pack
                     (const Opentelemetry__Proto__Profiles__V1development__Function   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__profiles__v1development__function__pack_to_buffer
                     (const Opentelemetry__Proto__Profiles__V1development__Function   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Profiles__V1development__Function *
       opentelemetry__proto__profiles__v1development__function__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__profiles__v1development__function__free_unpacked
                     (Opentelemetry__Proto__Profiles__V1development__Function *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Opentelemetry__Proto__Profiles__V1development__Profile_Closure)
                 (const Opentelemetry__Proto__Profiles__V1development__Profile *message,
                  void *closure_data);
typedef void (*Opentelemetry__Proto__Profiles__V1development__AttributeUnit_Closure)
                 (const Opentelemetry__Proto__Profiles__V1development__AttributeUnit *message,
                  void *closure_data);
typedef void (*Opentelemetry__Proto__Profiles__V1development__Link_Closure)
                 (const Opentelemetry__Proto__Profiles__V1development__Link *message,
                  void *closure_data);
typedef void (*Opentelemetry__Proto__Profiles__V1development__ValueType_Closure)
                 (const Opentelemetry__Proto__Profiles__V1development__ValueType *message,
                  void *closure_data);
typedef void (*Opentelemetry__Proto__Profiles__V1development__Sample_Closure)
                 (const Opentelemetry__Proto__Profiles__V1development__Sample *message,
                  void *closure_data);
typedef void (*Opentelemetry__Proto__Profiles__V1development__Label_Closure)
                 (const Opentelemetry__Proto__Profiles__V1development__Label *message,
                  void *closure_data);
typedef void (*Opentelemetry__Proto__Profiles__V1development__Mapping_Closure)
                 (const Opentelemetry__Proto__Profiles__V1development__Mapping *message,
                  void *closure_data);
typedef void (*Opentelemetry__Proto__Profiles__V1development__Location_Closure)
                 (const Opentelemetry__Proto__Profiles__V1development__Location *message,
                  void *closure_data);
typedef void (*Opentelemetry__Proto__Profiles__V1development__Line_Closure)
                 (const Opentelemetry__Proto__Profiles__V1development__Line *message,
                  void *closure_data);
typedef void (*Opentelemetry__Proto__Profiles__V1development__Function_Closure)
                 (const Opentelemetry__Proto__Profiles__V1development__Function *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    opentelemetry__proto__profiles__v1development__aggregation_temporality__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__profiles__v1development__profile__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__profiles__v1development__attribute_unit__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__profiles__v1development__link__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__profiles__v1development__value_type__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__profiles__v1development__sample__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__profiles__v1development__label__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__profiles__v1development__mapping__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__profiles__v1development__location__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__profiles__v1development__line__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__profiles__v1development__function__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_opentelemetry_2fproto_2fprofiles_2fv1development_2fpprofextended_2eproto__INCLUDED */
