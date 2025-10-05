#include <future>
#include <sys/resource.h>
#ifndef JSON_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structs
typedef enum {
    JSON_NULL,
    JSON_BOOL,
    JSON_NUMBER,
    JSON_STRING,
    JSON_OBJECT,
    JSON_ARRAY
} JsonType;

struct JsonValue; // forward declaration

typedef struct {
    char *key;
    struct JsonValue *value;
} JsonPair;

typedef struct {
    JsonPair *pairs;
    size_t count;
} JsonObject;

typedef struct {
    struct JsonValue **items;
    size_t count;
} JsonArray;

typedef struct JsonValue {
    JsonType type;
    union {
        int bool_value;
        float float_value;
        double number_value;
        char *string_value;
        JsonObject object_value;
        JsonArray array_value;
    };
} JsonValue;



// functions

/*----- Encoder and Decoder -----*/
char* JSON_encode(JsonValue Json);
JsonValue JSON_decode(char* buff);

/*----- Create and Modifier ----*/

JsonValue JSON_create();
// TODO add setters and getters


#endif



/*
 * {  --> object
 *  "Key1" : int, --> int
 *  "key2" : "string", --> string(char*)
 *  "key3" : {"key31" : val}, --> object
 *  "key4" : float,  --> float
 *  "key5" : double,
 *  "key6" : Bool,
 *  "key7" : ["Array",1,{"key73" : 1}]
 * }
 */
