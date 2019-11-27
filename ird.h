#ifndef __IR_ird__
#define __IR_ird__

#define _IR_offsetof(type, field) ((char *)&((type *) 64)->field - (char *) 64)


#line 37 "./ird.sprut"


#include "objstack.h"
#include "position.h"

/* Definitions of predefined types: */

typedef int integer_t;

typedef int bool_t;

typedef char *string_t;



#line 24 "ird.h"

typedef enum IR_node_mode_enum
{
  IR_NM_node,
  IR_NM_identifier,
  IR_NM_string,
  IR_NM_code_insertion,
  IR_NM_additional_code,
  IR_NM_keyword,
  IR_NM_identifier_keyword,
  IR_NM_string_keyword,
  IR_NM_declaration,
  IR_NM_code,
  IR_NM_local_code,
  IR_NM_import_code,
  IR_NM_export_code,
  IR_NM_description,
  IR_NM_trie_node_next_level,
  IR_NM_trie_node,
  IR_NM_keyword_set,
  IR_NM__root,
  IR_NM__error
} IR_node_mode_t;

extern short _IR_node_level [];

extern unsigned char _IR_SF_node [];

extern unsigned char _IR_SF_identifier [];

extern unsigned char _IR_SF_string [];

extern unsigned char _IR_SF_code_insertion [];

extern unsigned char _IR_SF_additional_code [];

extern unsigned char _IR_SF_keyword [];

extern unsigned char _IR_SF_identifier_keyword [];

extern unsigned char _IR_SF_string_keyword [];

extern unsigned char _IR_SF_declaration [];

extern unsigned char _IR_SF_code [];

extern unsigned char _IR_SF_local_code [];

extern unsigned char _IR_SF_import_code [];

extern unsigned char _IR_SF_export_code [];

extern unsigned char _IR_SF_description [];

extern unsigned char _IR_SF_trie_node_next_level [];

extern unsigned char _IR_SF_trie_node [];

extern unsigned char _IR_SF_keyword_set [];

extern unsigned char _IR_SF__root [];

extern unsigned char _IR_SF__error [];

extern unsigned char *_IR_is_type[];

extern void *_IR_class_structure_array [];

typedef struct IR_node *IR_node_t;

typedef struct _IR_double_link *IR_double_link_t;

struct _IR_double_link
{
  IR_node_t field_itself;
  IR_node_t link_owner;
  void (*set_function) (IR_node_t, IR_node_t);
  IR_double_link_t previous_link;
  IR_double_link_t next_link;
};

struct _IR_S_node
{
  position_t  position;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_node _IR_S_node;
} _IR_node;

struct _IR_S_identifier
{
  struct _IR_S_node _IR_M_node;
  string_t  identifier_itself;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_identifier _IR_S_identifier;
} _IR_identifier;

struct _IR_S_string
{
  struct _IR_S_node _IR_M_node;
  string_t  string_representation;
  string_t  string_itself;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_string _IR_S_string;
} _IR_string;

struct _IR_S_code_insertion
{
  struct _IR_S_node _IR_M_node;
  string_t  code_insertion_itself;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_code_insertion _IR_S_code_insertion;
} _IR_code_insertion;

struct _IR_S_additional_code
{
  struct _IR_S_node _IR_M_node;
  string_t  additional_code_itself;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_additional_code _IR_S_additional_code;
} _IR_additional_code;

struct _IR_S_keyword
{
  struct _IR_S_node _IR_M_node;
  IR_node_t  name;
  integer_t  frequency;
  IR_node_t  action;
  IR_node_t  next_keyword;
  bool_t  first_the_same_name_keyword_flag;
  IR_node_t  next_the_same_name_keyword;
  integer_t  keyword_name_index;
  IR_node_t  next_the_same_length_keyword;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_keyword _IR_S_keyword;
} _IR_keyword;

struct _IR_S_identifier_keyword
{
  struct _IR_S_keyword _IR_M_keyword;
  IR_node_t  identifier;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_identifier_keyword _IR_S_identifier_keyword;
} _IR_identifier_keyword;

struct _IR_S_string_keyword
{
  struct _IR_S_keyword _IR_M_keyword;
  IR_node_t  string;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_string_keyword _IR_S_string_keyword;
} _IR_string_keyword;

struct _IR_S_declaration
{
  struct _IR_S_node _IR_M_node;
  IR_node_t  next_declaration;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_declaration _IR_S_declaration;
} _IR_declaration;

struct _IR_S_code
{
  struct _IR_S_declaration _IR_M_declaration;
  IR_node_t  code_itself;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_code _IR_S_code;
} _IR_code;

struct _IR_S_local_code
{
  struct _IR_S_code _IR_M_code;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_local_code _IR_S_local_code;
} _IR_local_code;

struct _IR_S_import_code
{
  struct _IR_S_code _IR_M_code;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_import_code _IR_S_import_code;
} _IR_import_code;

struct _IR_S_export_code
{
  struct _IR_S_code _IR_M_code;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_export_code _IR_S_export_code;
} _IR_export_code;

struct _IR_S_description
{
  struct _IR_S_node _IR_M_node;
  IR_node_t  keyword_list;
  IR_node_t  additional_code;
  bool_t  other_is_present;
  position_t  other_position;
  IR_node_t  other_action;
  IR_node_t  declaration_list;
  IR_node_t  keyword_type;
  IR_node_t  keyword_set_list;
  integer_t  keywords_number;
  integer_t  keyword_names_number;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_description _IR_S_description;
} _IR_description;

struct _IR_S_trie_node_next_level
{
  IR_node_t  trie_node_list;
  integer_t  trie_node_list_index;
  integer_t  recognition_cost;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_trie_node_next_level _IR_S_trie_node_next_level;
} _IR_trie_node_next_level;

struct _IR_S_trie_node
{
  struct _IR_S_trie_node_next_level _IR_M_trie_node_next_level;
  integer_t  character_code;
  IR_node_t  next_trie_node;
  IR_node_t  keyword;
  IR_node_t  upper_trie_node_level;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_trie_node _IR_S_trie_node;
} _IR_trie_node;

struct _IR_S_keyword_set
{
  struct _IR_S_trie_node_next_level _IR_M_trie_node_next_level;
  integer_t  length;
  IR_node_t  the_same_length_keyword_list;
  integer_t  the_same_length_keywords_number;
  IR_node_t  next_keyword_set;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_keyword_set _IR_S_keyword_set;
} _IR_keyword_set;

typedef struct IR_node
{
  IR_node_mode_t _IR_node_mode;
} _IR__root;

typedef struct
{
  IR_node_mode_t _IR_node_mode;
} _IR__error;

#define IR_NODE_MODE(t) ((t)->_IR_node_mode)

extern const char *IR_node_name[];

extern unsigned char IR_node_size[];

#define IR_NODE_LEVEL(node) _IR_node_level [IR_NODE_MODE (node)]

#define IR_IS_TYPE(type, super) ((_IR_is_type [super] [type /8] >> (type % 8)) & 1)

#define IR_IS_OF_TYPE(node, super)IR_IS_TYPE (IR_NODE_MODE (node), super)

extern void _IR_set_double_field_value
  (IR_double_link_t link, IR_node_t value, int disp, int flag);

extern IR_double_link_t IR__first_double_link (IR_node_t node);

#define IR__next_double_link(prev_double_link) ((prev_double_link)->next_link)

#define IR__previous_double_link(next_double_link) ((next_double_link)->previous_link)

#define IR__owner(link) ((link)->link_owner)

#define IR_position(_node) (((_IR_node *) (_node))->_IR_S_node.position)

#define IR_identifier_itself(_node) (((_IR_identifier *) (_node))->_IR_S_identifier.identifier_itself)

#define IR_string_representation(_node) (((_IR_string *) (_node))->_IR_S_string.string_representation)

#define IR_string_itself(_node) (((_IR_string *) (_node))->_IR_S_string.string_itself)

#define IR_code_insertion_itself(_node) (((_IR_code_insertion *) (_node))->_IR_S_code_insertion.code_insertion_itself)

#define IR_additional_code_itself(_node) (((_IR_additional_code *) (_node))->_IR_S_additional_code.additional_code_itself)

#define IR_name(_node) (((_IR_keyword *) (_node))->_IR_S_keyword.name)

#define IR_frequency(_node) (((_IR_keyword *) (_node))->_IR_S_keyword.frequency)

#define IR_action(_node) (((_IR_keyword *) (_node))->_IR_S_keyword.action)

#define IR_next_keyword(_node) (((_IR_keyword *) (_node))->_IR_S_keyword.next_keyword)

#define IR_first_the_same_name_keyword_flag(_node) (((_IR_keyword *) (_node))->_IR_S_keyword.first_the_same_name_keyword_flag)

#define IR_next_the_same_name_keyword(_node) (((_IR_keyword *) (_node))->_IR_S_keyword.next_the_same_name_keyword)

#define IR_keyword_name_index(_node) (((_IR_keyword *) (_node))->_IR_S_keyword.keyword_name_index)

#define IR_next_the_same_length_keyword(_node) (((_IR_keyword *) (_node))->_IR_S_keyword.next_the_same_length_keyword)

#define IR_identifier(_node) (((_IR_identifier_keyword *) (_node))->_IR_S_identifier_keyword.identifier)

#define IR_string(_node) (((_IR_string_keyword *) (_node))->_IR_S_string_keyword.string)

#define IR_next_declaration(_node) (((_IR_declaration *) (_node))->_IR_S_declaration.next_declaration)

#define IR_code_itself(_node) (((_IR_code *) (_node))->_IR_S_code.code_itself)

#define IR_keyword_list(_node) (((_IR_description *) (_node))->_IR_S_description.keyword_list)

#define IR_additional_code(_node) (((_IR_description *) (_node))->_IR_S_description.additional_code)

#define IR_other_is_present(_node) (((_IR_description *) (_node))->_IR_S_description.other_is_present)

#define IR_other_position(_node) (((_IR_description *) (_node))->_IR_S_description.other_position)

#define IR_other_action(_node) (((_IR_description *) (_node))->_IR_S_description.other_action)

#define IR_declaration_list(_node) (((_IR_description *) (_node))->_IR_S_description.declaration_list)

#define IR_keyword_type(_node) (((_IR_description *) (_node))->_IR_S_description.keyword_type)

#define IR_keyword_set_list(_node) (((_IR_description *) (_node))->_IR_S_description.keyword_set_list)

#define IR_keywords_number(_node) (((_IR_description *) (_node))->_IR_S_description.keywords_number)

#define IR_keyword_names_number(_node) (((_IR_description *) (_node))->_IR_S_description.keyword_names_number)

#define IR_trie_node_list(_node) (((_IR_trie_node_next_level *) (_node))->_IR_S_trie_node_next_level.trie_node_list)

#define IR_trie_node_list_index(_node) (((_IR_trie_node_next_level *) (_node))->_IR_S_trie_node_next_level.trie_node_list_index)

#define IR_recognition_cost(_node) (((_IR_trie_node_next_level *) (_node))->_IR_S_trie_node_next_level.recognition_cost)

#define IR_character_code(_node) (((_IR_trie_node *) (_node))->_IR_S_trie_node.character_code)

#define IR_next_trie_node(_node) (((_IR_trie_node *) (_node))->_IR_S_trie_node.next_trie_node)

#define IR_keyword(_node) (((_IR_trie_node *) (_node))->_IR_S_trie_node.keyword)

#define IR_upper_trie_node_level(_node) (((_IR_trie_node *) (_node))->_IR_S_trie_node.upper_trie_node_level)

#define IR_length(_node) (((_IR_keyword_set *) (_node))->_IR_S_keyword_set.length)

#define IR_the_same_length_keyword_list(_node) (((_IR_keyword_set *) (_node))->_IR_S_keyword_set.the_same_length_keyword_list)

#define IR_the_same_length_keywords_number(_node) (((_IR_keyword_set *) (_node))->_IR_S_keyword_set.the_same_length_keywords_number)

#define IR_next_keyword_set(_node) (((_IR_keyword_set *) (_node))->_IR_S_keyword_set.next_keyword_set)

extern void IR__set_double_link (IR_double_link_t link, IR_node_t value);

#define IR_set_position(_node, _value) ((((_IR_node *) (_node))->_IR_S_node.position) = (_value))

#define IR_set_identifier_itself(_node, _value) ((((_IR_identifier *) (_node))->_IR_S_identifier.identifier_itself) = (_value))

#define IR_set_string_representation(_node, _value) ((((_IR_string *) (_node))->_IR_S_string.string_representation) = (_value))

#define IR_set_string_itself(_node, _value) ((((_IR_string *) (_node))->_IR_S_string.string_itself) = (_value))

#define IR_set_code_insertion_itself(_node, _value) ((((_IR_code_insertion *) (_node))->_IR_S_code_insertion.code_insertion_itself) = (_value))

#define IR_set_additional_code_itself(_node, _value) ((((_IR_additional_code *) (_node))->_IR_S_additional_code.additional_code_itself) = (_value))

#define IR_set_name(_node, _value) ((((_IR_keyword *) (_node))->_IR_S_keyword.name) = (_value))

#define IR_set_frequency(_node, _value) ((((_IR_keyword *) (_node))->_IR_S_keyword.frequency) = (_value))

#define IR_set_action(_node, _value) ((((_IR_keyword *) (_node))->_IR_S_keyword.action) = (_value))

#define IR_set_next_keyword(_node, _value) ((((_IR_keyword *) (_node))->_IR_S_keyword.next_keyword) = (_value))

#define IR_set_first_the_same_name_keyword_flag(_node, _value) ((((_IR_keyword *) (_node))->_IR_S_keyword.first_the_same_name_keyword_flag) = (_value))

#define IR_set_next_the_same_name_keyword(_node, _value) ((((_IR_keyword *) (_node))->_IR_S_keyword.next_the_same_name_keyword) = (_value))

#define IR_set_keyword_name_index(_node, _value) ((((_IR_keyword *) (_node))->_IR_S_keyword.keyword_name_index) = (_value))

#define IR_set_next_the_same_length_keyword(_node, _value) ((((_IR_keyword *) (_node))->_IR_S_keyword.next_the_same_length_keyword) = (_value))

#define IR_set_identifier(_node, _value) ((((_IR_identifier_keyword *) (_node))->_IR_S_identifier_keyword.identifier) = (_value))

#define IR_set_string(_node, _value) ((((_IR_string_keyword *) (_node))->_IR_S_string_keyword.string) = (_value))

#define IR_set_next_declaration(_node, _value) ((((_IR_declaration *) (_node))->_IR_S_declaration.next_declaration) = (_value))

#define IR_set_code_itself(_node, _value) ((((_IR_code *) (_node))->_IR_S_code.code_itself) = (_value))

#define IR_set_keyword_list(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.keyword_list) = (_value))

#define IR_set_additional_code(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.additional_code) = (_value))

#define IR_set_other_is_present(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.other_is_present) = (_value))

#define IR_set_other_position(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.other_position) = (_value))

#define IR_set_other_action(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.other_action) = (_value))

#define IR_set_declaration_list(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.declaration_list) = (_value))

#define IR_set_keyword_type(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.keyword_type) = (_value))

#define IR_set_keyword_set_list(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.keyword_set_list) = (_value))

#define IR_set_keywords_number(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.keywords_number) = (_value))

#define IR_set_keyword_names_number(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.keyword_names_number) = (_value))

#define IR_set_trie_node_list(_node, _value) ((((_IR_trie_node_next_level *) (_node))->_IR_S_trie_node_next_level.trie_node_list) = (_value))

#define IR_set_trie_node_list_index(_node, _value) ((((_IR_trie_node_next_level *) (_node))->_IR_S_trie_node_next_level.trie_node_list_index) = (_value))

#define IR_set_recognition_cost(_node, _value) ((((_IR_trie_node_next_level *) (_node))->_IR_S_trie_node_next_level.recognition_cost) = (_value))

#define IR_set_character_code(_node, _value) ((((_IR_trie_node *) (_node))->_IR_S_trie_node.character_code) = (_value))

#define IR_set_next_trie_node(_node, _value) ((((_IR_trie_node *) (_node))->_IR_S_trie_node.next_trie_node) = (_value))

#define IR_set_keyword(_node, _value) ((((_IR_trie_node *) (_node))->_IR_S_trie_node.keyword) = (_value))

#define IR_set_upper_trie_node_level(_node, _value) ((((_IR_trie_node *) (_node))->_IR_S_trie_node.upper_trie_node_level) = (_value))

#define IR_set_length(_node, _value) ((((_IR_keyword_set *) (_node))->_IR_S_keyword_set.length) = (_value))

#define IR_set_the_same_length_keyword_list(_node, _value) ((((_IR_keyword_set *) (_node))->_IR_S_keyword_set.the_same_length_keyword_list) = (_value))

#define IR_set_the_same_length_keywords_number(_node, _value) ((((_IR_keyword_set *) (_node))->_IR_S_keyword_set.the_same_length_keywords_number) = (_value))

#define IR_set_next_keyword_set(_node, _value) ((((_IR_keyword_set *) (_node))->_IR_S_keyword_set.next_keyword_set) = (_value))

extern IR_node_t IR_create_node (IR_node_mode_t node_mode);

extern IR_node_t IR_new_identifier
(position_t position,
 string_t identifier_itself);

extern IR_node_t IR_new_string
(position_t position,
 string_t string_representation,
 string_t string_itself);

extern IR_node_t IR_new_code_insertion
(position_t position,
 string_t code_insertion_itself);

extern IR_node_t IR_new_additional_code
(position_t position,
 string_t additional_code_itself);

extern IR_node_t IR_new_identifier_keyword
(position_t position,
 IR_node_t name,
 integer_t frequency,
 IR_node_t action,
 IR_node_t next_keyword,
 IR_node_t identifier);

extern IR_node_t IR_new_string_keyword
(position_t position,
 IR_node_t name,
 integer_t frequency,
 IR_node_t action,
 IR_node_t next_keyword,
 IR_node_t string);

extern IR_node_t IR_new_local_code
(position_t position,
 IR_node_t next_declaration,
 IR_node_t code_itself);

extern IR_node_t IR_new_import_code
(position_t position,
 IR_node_t next_declaration,
 IR_node_t code_itself);

extern IR_node_t IR_new_export_code
(position_t position,
 IR_node_t next_declaration,
 IR_node_t code_itself);

extern IR_node_t IR_new_description
(position_t position,
 IR_node_t declaration_list,
 IR_node_t keyword_type);

extern IR_node_t IR_new_trie_node
();

extern IR_node_t IR_new_keyword_set
(integer_t length,
 IR_node_t the_same_length_keyword_list,
 integer_t the_same_length_keywords_number,
 IR_node_t next_keyword_set);

extern void IR_start (void);

extern void IR_stop (void);


#line 53 "./ird.sprut"


/* These macros for storage management of Shilka internal representation: */

/* Start work with the storage manager -- see Sprut documentation. */

#define IR_START_ALLOC()    OS_CREATE (irp, 0)

/* Finish work with the storage manager -- see Sprut documentation. */

#define IR_STOP_ALLOC()     OS_DELETE (irp)

/* Allocate storage for internal representation of given size
   -- see Sprut documentation. */

#define IR_ALLOC(ptr, size, ptr_type)\
  do {\
    OS_TOP_EXPAND (irp, size); ptr = (ptr_type) OS_TOP_BEGIN (irp);\
    OS_TOP_FINISH (irp);\
  } while (0);

/* Free storage of internal representation of given size -- see Sprut
   documentation. */

#define IR_FREE(ptr, size)


/* These macros are analogous to ones of package `object-stack'
   worked with storage of Sprut internal representation: */

/* Start new internal representation object -- see also package
   `object-stack'. */

#define IR_TOP_FINISH()  OS_TOP_FINISH (irp)

/* Nullify current internal representation object -- see also package
   `object-stack'. */

#define IR_TOP_NULLIFY()  OS_TOP_NULLIFY (irp)

/* Shorten current internal representation object on given number bytes -- see
   also package `object-stack'. */

#define IR_TOP_SHORTEN(length) OS_TOP_SHORTEN (irp, length)

/* Return start address of current internal representation object -- see also
   package `object-stack'. */

#define IR_TOP_BEGIN()  OS_TOP_BEGIN (irp)

/* Return length of current internal representation object in bytes -- see
   also package `object-stack'. */

#define IR_TOP_LENGTH()  OS_TOP_LENGTH (irp)

/* Expand current internal representation object -- see also package
   `object-stack'. */

#define IR_TOP_EXPAND(length)  OS_TOP_EXPAND (irp, length)

/* Add byte to the end of current internal representation object -- see also
   package `object-stack'. */

#define IR_TOP_ADD_BYTE(b)  OS_TOP_ADD_BYTE (irp, b)

/* Add string to the end of current internal representation object -- see also
   package `object-stack'. */

#define IR_TOP_ADD_STRING(str)  OS_TOP_ADD_STRING (irp, str)

/* Add memory of given length to the end of current internal representation
   object -- see also package `object-stack'. */

#define IR_TOP_ADD_MEMORY(mem, length)  OS_TOP_ADD_MEMORY (irp, mem, length)

extern os_t irp;

const char *keyword_representation (IR_node_t keyword);
const char *keyword_string (IR_node_t keyword);



#line 673 "ird.h"
#endif /* __IR_ird__ */
