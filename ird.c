#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ird.h"


#line 135 "./ird.sprut"


/* All internal representation storage is implemented by object stack.  See
   package `object-stack'. */

os_t irp;


#line 17 "ird.c"
#ifndef IR_START_ALLOC
#define IR_START_ALLOC()
#endif

#ifndef IR_STOP_ALLOC
#define IR_STOP_ALLOC()
#endif

#ifndef IR_ALLOC
#define IR_ALLOC(ptr, size, ptr_type) ((ptr) = (ptr_type) malloc (size))
#endif

#ifndef IR_FREE
#define IR_FREE(ptr, size) free (ptr)
#endif

#ifndef IR_BEGIN_IR_node_t
#define IR_BEGIN_IR_node_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_IR_node_t
#define IR_END_IR_node_t(a)
#endif

#ifndef IR_COPY_IR_node_t
#define IR_COPY_IR_node_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_IR_node_t
#define IR_EQUAL_IR_node_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_IR_node_t
#define IR_PRINT_IR_node_t(a) printf ("%lx", (unsigned long) (a))
#endif

#ifndef IR_INPUT_IR_node_t
#define IR_INPUT_IR_node_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_IR_node_t
#define IR_OUTPUT_IR_node_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_BEGIN_integer_t
#define IR_BEGIN_integer_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_integer_t
#define IR_END_integer_t(a)
#endif

#ifndef IR_COPY_integer_t
#define IR_COPY_integer_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_integer_t
#define IR_EQUAL_integer_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_integer_t
#define IR_PRINT_integer_t(a)
#endif

#ifndef IR_INPUT_integer_t
#define IR_INPUT_integer_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_integer_t
#define IR_OUTPUT_integer_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_BEGIN_bool_t
#define IR_BEGIN_bool_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_bool_t
#define IR_END_bool_t(a)
#endif

#ifndef IR_COPY_bool_t
#define IR_COPY_bool_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_bool_t
#define IR_EQUAL_bool_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_bool_t
#define IR_PRINT_bool_t(a)
#endif

#ifndef IR_INPUT_bool_t
#define IR_INPUT_bool_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_bool_t
#define IR_OUTPUT_bool_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_BEGIN_string_t
#define IR_BEGIN_string_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_string_t
#define IR_END_string_t(a)
#endif

#ifndef IR_COPY_string_t
#define IR_COPY_string_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_string_t
#define IR_EQUAL_string_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_string_t
#define IR_PRINT_string_t(a)
#endif

#ifndef IR_INPUT_string_t
#define IR_INPUT_string_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_string_t
#define IR_OUTPUT_string_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_BEGIN_position_t
#define IR_BEGIN_position_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_position_t
#define IR_END_position_t(a)
#endif

#ifndef IR_COPY_position_t
#define IR_COPY_position_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_position_t
#define IR_EQUAL_position_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_position_t
#define IR_PRINT_position_t(a)
#endif

#ifndef IR_INPUT_position_t
#define IR_INPUT_position_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_position_t
#define IR_OUTPUT_position_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_BEGIN_reservation_sets_list_t
#define IR_BEGIN_reservation_sets_list_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_reservation_sets_list_t
#define IR_END_reservation_sets_list_t(a)
#endif

#ifndef IR_COPY_reservation_sets_list_t
#define IR_COPY_reservation_sets_list_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_reservation_sets_list_t
#define IR_EQUAL_reservation_sets_list_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_reservation_sets_list_t
#define IR_PRINT_reservation_sets_list_t(a)
#endif

#ifndef IR_INPUT_reservation_sets_list_t
#define IR_INPUT_reservation_sets_list_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_reservation_sets_list_t
#define IR_OUTPUT_reservation_sets_list_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

short _IR_node_level [] =
{
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};

unsigned char _IR_SF_node [] =
{255, 63, 0
};

unsigned char _IR_SF_identifier [] =
{2, 0, 0
};

unsigned char _IR_SF_string [] =
{4, 0, 0
};

unsigned char _IR_SF_code_insertion [] =
{8, 0, 0
};

unsigned char _IR_SF_additional_code [] =
{16, 0, 0
};

unsigned char _IR_SF_keyword [] =
{224, 0, 0
};

unsigned char _IR_SF_identifier_keyword [] =
{64, 0, 0
};

unsigned char _IR_SF_string_keyword [] =
{128, 0, 0
};

unsigned char _IR_SF_declaration [] =
{0, 31, 0
};

unsigned char _IR_SF_code [] =
{0, 30, 0
};

unsigned char _IR_SF_local_code [] =
{0, 4, 0
};

unsigned char _IR_SF_import_code [] =
{0, 8, 0
};

unsigned char _IR_SF_export_code [] =
{0, 16, 0
};

unsigned char _IR_SF_description [] =
{0, 32, 0
};

unsigned char _IR_SF_trie_node_next_level [] =
{0, 192, 1
};

unsigned char _IR_SF_trie_node [] =
{0, 128, 0
};

unsigned char _IR_SF_keyword_set [] =
{0, 0, 1
};

unsigned char _IR_SF__root [] =
{255, 255, 7
};

unsigned char _IR_SF__error [] =
{0, 0, 4
};

unsigned char *_IR_is_type[] =
{
_IR_SF_node,
_IR_SF_identifier,
_IR_SF_string,
_IR_SF_code_insertion,
_IR_SF_additional_code,
_IR_SF_keyword,
_IR_SF_identifier_keyword,
_IR_SF_string_keyword,
_IR_SF_declaration,
_IR_SF_code,
_IR_SF_local_code,
_IR_SF_import_code,
_IR_SF_export_code,
_IR_SF_description,
_IR_SF_trie_node_next_level,
_IR_SF_trie_node,
_IR_SF_keyword_set,
_IR_SF__root,
_IR_SF__error
};

void *_IR_class_structure_array [] =
{
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
};

const char *IR_node_name[] =
{
  "node",
  "identifier",
  "string",
  "code_insertion",
  "additional_code",
  "keyword",
  "identifier_keyword",
  "string_keyword",
  "declaration",
  "code",
  "local_code",
  "import_code",
  "export_code",
  "description",
  "trie_node_next_level",
  "trie_node",
  "keyword_set",
  "%root",
  "%error"
};

unsigned char IR_node_size[] =
{
  sizeof (_IR_node),
  sizeof (_IR_identifier),
  sizeof (_IR_string),
  sizeof (_IR_code_insertion),
  sizeof (_IR_additional_code),
  sizeof (_IR_keyword),
  sizeof (_IR_identifier_keyword),
  sizeof (_IR_string_keyword),
  sizeof (_IR_declaration),
  sizeof (_IR_code),
  sizeof (_IR_local_code),
  sizeof (_IR_import_code),
  sizeof (_IR_export_code),
  sizeof (_IR_description),
  sizeof (_IR_trie_node_next_level),
  sizeof (_IR_trie_node),
  sizeof (_IR_keyword_set),
  sizeof (_IR__root),
  sizeof (_IR__error)
};

static int (* _IR_traverse_guard_function_variable) (IR_node_t node);

static int _IR_current_graph_pass_number;

void _IR_set_double_field_value
  (IR_double_link_t link, IR_node_t value, int disp, int flag)
{
}

IR_double_link_t IR__first_double_link (IR_node_t node)
{
  return NULL;
}

void IR__set_double_link (IR_double_link_t link, IR_node_t value)
{
#ifdef __IR_DEBUG__
  if (link == NULL)
    abort ();
#endif /* __IR_DEBUG__ */
  (*link->set_function) (link->link_owner, value);
}

static void _IR_node_field_initiation (IR_node_mode_t node_mode, IR_node_t node)
{
  switch (node_mode)
    {
    case IR_NM_node:
      IR_BEGIN_position_t ((((_IR_node *) node)->_IR_S_node.position));
      break;
    case IR_NM_identifier:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_identifier *) node)->_IR_S_identifier._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_string_t ((((_IR_identifier *) node)->_IR_S_identifier.identifier_itself));
      break;
    case IR_NM_string:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_string *) node)->_IR_S_string._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_string_t ((((_IR_string *) node)->_IR_S_string.string_representation));
      IR_BEGIN_string_t ((((_IR_string *) node)->_IR_S_string.string_itself));
      break;
    case IR_NM_code_insertion:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_code_insertion *) node)->_IR_S_code_insertion._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_string_t ((((_IR_code_insertion *) node)->_IR_S_code_insertion.code_insertion_itself));
      break;
    case IR_NM_additional_code:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_additional_code *) node)->_IR_S_additional_code._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_string_t ((((_IR_additional_code *) node)->_IR_S_additional_code.additional_code_itself));
      break;
    case IR_NM_keyword:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_keyword *) node)->_IR_S_keyword._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_IR_node_t ((((_IR_keyword *) node)->_IR_S_keyword.name));
      IR_BEGIN_integer_t ((((_IR_keyword *) node)->_IR_S_keyword.frequency));
      IR_BEGIN_IR_node_t ((((_IR_keyword *) node)->_IR_S_keyword.action));
      IR_BEGIN_IR_node_t ((((_IR_keyword *) node)->_IR_S_keyword.next_keyword));
      IR_BEGIN_bool_t ((((_IR_keyword *) node)->_IR_S_keyword.first_the_same_name_keyword_flag));
      IR_BEGIN_IR_node_t ((((_IR_keyword *) node)->_IR_S_keyword.next_the_same_name_keyword));
      IR_BEGIN_integer_t ((((_IR_keyword *) node)->_IR_S_keyword.keyword_name_index));
      IR_BEGIN_IR_node_t ((((_IR_keyword *) node)->_IR_S_keyword.next_the_same_length_keyword));
      break;
    case IR_NM_identifier_keyword:
      _IR_node_field_initiation (IR_NM_keyword, (IR_node_t) ((char *) &((_IR_identifier_keyword *) node)->_IR_S_identifier_keyword._IR_M_keyword - _IR_offsetof (_IR_keyword, _IR_S_keyword)));
      IR_BEGIN_IR_node_t ((((_IR_identifier_keyword *) node)->_IR_S_identifier_keyword.identifier));
      break;
    case IR_NM_string_keyword:
      _IR_node_field_initiation (IR_NM_keyword, (IR_node_t) ((char *) &((_IR_string_keyword *) node)->_IR_S_string_keyword._IR_M_keyword - _IR_offsetof (_IR_keyword, _IR_S_keyword)));
      IR_BEGIN_IR_node_t ((((_IR_string_keyword *) node)->_IR_S_string_keyword.string));
      break;
    case IR_NM_declaration:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_declaration *) node)->_IR_S_declaration._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_IR_node_t ((((_IR_declaration *) node)->_IR_S_declaration.next_declaration));
      break;
    case IR_NM_code:
      _IR_node_field_initiation (IR_NM_declaration, (IR_node_t) ((char *) &((_IR_code *) node)->_IR_S_code._IR_M_declaration - _IR_offsetof (_IR_declaration, _IR_S_declaration)));
      IR_BEGIN_IR_node_t ((((_IR_code *) node)->_IR_S_code.code_itself));
      break;
    case IR_NM_local_code:
      _IR_node_field_initiation (IR_NM_code, (IR_node_t) ((char *) &((_IR_local_code *) node)->_IR_S_local_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_import_code:
      _IR_node_field_initiation (IR_NM_code, (IR_node_t) ((char *) &((_IR_import_code *) node)->_IR_S_import_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_export_code:
      _IR_node_field_initiation (IR_NM_code, (IR_node_t) ((char *) &((_IR_export_code *) node)->_IR_S_export_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_description:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_description *) node)->_IR_S_description._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.keyword_list));
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.additional_code));
      IR_BEGIN_bool_t ((((_IR_description *) node)->_IR_S_description.other_is_present));
{

#line 254 "./ird.sprut"
(((_IR_description *) node)->_IR_S_description.other_is_present) = 0; /*FALSE*/

#line 484 "ird.c"
}
      IR_BEGIN_position_t ((((_IR_description *) node)->_IR_S_description.other_position));
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.other_action));
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.declaration_list));
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.keyword_type));
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.keyword_set_list));
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.keywords_number));
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.keyword_names_number));
      break;
    case IR_NM_trie_node_next_level:
      IR_BEGIN_IR_node_t ((((_IR_trie_node_next_level *) node)->_IR_S_trie_node_next_level.trie_node_list));
      IR_BEGIN_integer_t ((((_IR_trie_node_next_level *) node)->_IR_S_trie_node_next_level.trie_node_list_index));
      IR_BEGIN_integer_t ((((_IR_trie_node_next_level *) node)->_IR_S_trie_node_next_level.recognition_cost));
      break;
    case IR_NM_trie_node:
      _IR_node_field_initiation (IR_NM_trie_node_next_level, (IR_node_t) ((char *) &((_IR_trie_node *) node)->_IR_S_trie_node._IR_M_trie_node_next_level - _IR_offsetof (_IR_trie_node_next_level, _IR_S_trie_node_next_level)));
      IR_BEGIN_integer_t ((((_IR_trie_node *) node)->_IR_S_trie_node.character_code));
      IR_BEGIN_IR_node_t ((((_IR_trie_node *) node)->_IR_S_trie_node.next_trie_node));
      IR_BEGIN_IR_node_t ((((_IR_trie_node *) node)->_IR_S_trie_node.keyword));
      IR_BEGIN_IR_node_t ((((_IR_trie_node *) node)->_IR_S_trie_node.upper_trie_node_level));
      break;
    case IR_NM_keyword_set:
      _IR_node_field_initiation (IR_NM_trie_node_next_level, (IR_node_t) ((char *) &((_IR_keyword_set *) node)->_IR_S_keyword_set._IR_M_trie_node_next_level - _IR_offsetof (_IR_trie_node_next_level, _IR_S_trie_node_next_level)));
      IR_BEGIN_integer_t ((((_IR_keyword_set *) node)->_IR_S_keyword_set.length));
      IR_BEGIN_IR_node_t ((((_IR_keyword_set *) node)->_IR_S_keyword_set.the_same_length_keyword_list));
      IR_BEGIN_integer_t ((((_IR_keyword_set *) node)->_IR_S_keyword_set.the_same_length_keywords_number));
      IR_BEGIN_IR_node_t ((((_IR_keyword_set *) node)->_IR_S_keyword_set.next_keyword_set));
      break;
    case IR_NM__error:
      break;
    default:
      abort ();
      break;
    }
}

IR_node_t IR_create_node (IR_node_mode_t node_mode)
{
 IR_node_t _result;

  IR_ALLOC (_result, IR_node_size [node_mode], IR_node_t);
#ifdef __IR_DEBUG__
  if (_result == NULL)
    abort ();
#endif /* __IR_DEBUG__ */
  IR_NODE_MODE (_result) = node_mode;
  _IR_node_field_initiation (node_mode, _result);
  return _result;
}

IR_node_t IR_new_identifier
(position_t position,
 string_t identifier_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_identifier);
  (((_IR_identifier *) _result)->_IR_S_identifier._IR_M_node.position) = position;
  (((_IR_identifier *) _result)->_IR_S_identifier.identifier_itself) = identifier_itself;
  return _result;
}

IR_node_t IR_new_string
(position_t position,
 string_t string_representation,
 string_t string_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_string);
  (((_IR_string *) _result)->_IR_S_string._IR_M_node.position) = position;
  (((_IR_string *) _result)->_IR_S_string.string_representation) = string_representation;
  (((_IR_string *) _result)->_IR_S_string.string_itself) = string_itself;
  return _result;
}

IR_node_t IR_new_code_insertion
(position_t position,
 string_t code_insertion_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_code_insertion);
  (((_IR_code_insertion *) _result)->_IR_S_code_insertion._IR_M_node.position) = position;
  (((_IR_code_insertion *) _result)->_IR_S_code_insertion.code_insertion_itself) = code_insertion_itself;
  return _result;
}

IR_node_t IR_new_additional_code
(position_t position,
 string_t additional_code_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_additional_code);
  (((_IR_additional_code *) _result)->_IR_S_additional_code._IR_M_node.position) = position;
  (((_IR_additional_code *) _result)->_IR_S_additional_code.additional_code_itself) = additional_code_itself;
  return _result;
}

IR_node_t IR_new_identifier_keyword
(position_t position,
 IR_node_t name,
 integer_t frequency,
 IR_node_t action,
 IR_node_t next_keyword,
 IR_node_t identifier)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_identifier_keyword);
  (((_IR_identifier_keyword *) _result)->_IR_S_identifier_keyword._IR_M_keyword._IR_M_node.position) = position;
  (((_IR_identifier_keyword *) _result)->_IR_S_identifier_keyword._IR_M_keyword.name) = name;
  (((_IR_identifier_keyword *) _result)->_IR_S_identifier_keyword._IR_M_keyword.frequency) = frequency;
  (((_IR_identifier_keyword *) _result)->_IR_S_identifier_keyword._IR_M_keyword.action) = action;
  (((_IR_identifier_keyword *) _result)->_IR_S_identifier_keyword._IR_M_keyword.next_keyword) = next_keyword;
  (((_IR_identifier_keyword *) _result)->_IR_S_identifier_keyword.identifier) = identifier;
  return _result;
}

IR_node_t IR_new_string_keyword
(position_t position,
 IR_node_t name,
 integer_t frequency,
 IR_node_t action,
 IR_node_t next_keyword,
 IR_node_t string)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_string_keyword);
  (((_IR_string_keyword *) _result)->_IR_S_string_keyword._IR_M_keyword._IR_M_node.position) = position;
  (((_IR_string_keyword *) _result)->_IR_S_string_keyword._IR_M_keyword.name) = name;
  (((_IR_string_keyword *) _result)->_IR_S_string_keyword._IR_M_keyword.frequency) = frequency;
  (((_IR_string_keyword *) _result)->_IR_S_string_keyword._IR_M_keyword.action) = action;
  (((_IR_string_keyword *) _result)->_IR_S_string_keyword._IR_M_keyword.next_keyword) = next_keyword;
  (((_IR_string_keyword *) _result)->_IR_S_string_keyword.string) = string;
  return _result;
}

IR_node_t IR_new_local_code
(position_t position,
 IR_node_t next_declaration,
 IR_node_t code_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_local_code);
  (((_IR_local_code *) _result)->_IR_S_local_code._IR_M_code._IR_M_declaration._IR_M_node.position) = position;
  (((_IR_local_code *) _result)->_IR_S_local_code._IR_M_code._IR_M_declaration.next_declaration) = next_declaration;
  (((_IR_local_code *) _result)->_IR_S_local_code._IR_M_code.code_itself) = code_itself;
  return _result;
}

IR_node_t IR_new_import_code
(position_t position,
 IR_node_t next_declaration,
 IR_node_t code_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_import_code);
  (((_IR_import_code *) _result)->_IR_S_import_code._IR_M_code._IR_M_declaration._IR_M_node.position) = position;
  (((_IR_import_code *) _result)->_IR_S_import_code._IR_M_code._IR_M_declaration.next_declaration) = next_declaration;
  (((_IR_import_code *) _result)->_IR_S_import_code._IR_M_code.code_itself) = code_itself;
  return _result;
}

IR_node_t IR_new_export_code
(position_t position,
 IR_node_t next_declaration,
 IR_node_t code_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_export_code);
  (((_IR_export_code *) _result)->_IR_S_export_code._IR_M_code._IR_M_declaration._IR_M_node.position) = position;
  (((_IR_export_code *) _result)->_IR_S_export_code._IR_M_code._IR_M_declaration.next_declaration) = next_declaration;
  (((_IR_export_code *) _result)->_IR_S_export_code._IR_M_code.code_itself) = code_itself;
  return _result;
}

IR_node_t IR_new_description
(position_t position,
 IR_node_t declaration_list,
 IR_node_t keyword_type)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_description);
  (((_IR_description *) _result)->_IR_S_description._IR_M_node.position) = position;
  (((_IR_description *) _result)->_IR_S_description.declaration_list) = declaration_list;
  (((_IR_description *) _result)->_IR_S_description.keyword_type) = keyword_type;
  return _result;
}

IR_node_t IR_new_trie_node
()
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_trie_node);
  return _result;
}

IR_node_t IR_new_keyword_set
(integer_t length,
 IR_node_t the_same_length_keyword_list,
 integer_t the_same_length_keywords_number,
 IR_node_t next_keyword_set)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_keyword_set);
  (((_IR_keyword_set *) _result)->_IR_S_keyword_set.length) = length;
  (((_IR_keyword_set *) _result)->_IR_S_keyword_set.the_same_length_keyword_list) = the_same_length_keyword_list;
  (((_IR_keyword_set *) _result)->_IR_S_keyword_set.the_same_length_keywords_number) = the_same_length_keywords_number;
  (((_IR_keyword_set *) _result)->_IR_S_keyword_set.next_keyword_set) = next_keyword_set;
  return _result;
}

void IR_start (void)
{
#ifdef __IR_DEBUG__
  if (sizeof (_IR_node) > 255)
    {
      fprintf (stderr, "Very long node `node' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_identifier) > 255)
    {
      fprintf (stderr, "Very long node `identifier' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_string) > 255)
    {
      fprintf (stderr, "Very long node `string' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_code_insertion) > 255)
    {
      fprintf (stderr, "Very long node `code_insertion' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_additional_code) > 255)
    {
      fprintf (stderr, "Very long node `additional_code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_keyword) > 255)
    {
      fprintf (stderr, "Very long node `keyword' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_identifier_keyword) > 255)
    {
      fprintf (stderr, "Very long node `identifier_keyword' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_string_keyword) > 255)
    {
      fprintf (stderr, "Very long node `string_keyword' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_declaration) > 255)
    {
      fprintf (stderr, "Very long node `declaration' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_code) > 255)
    {
      fprintf (stderr, "Very long node `code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_local_code) > 255)
    {
      fprintf (stderr, "Very long node `local_code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_import_code) > 255)
    {
      fprintf (stderr, "Very long node `import_code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_export_code) > 255)
    {
      fprintf (stderr, "Very long node `export_code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_description) > 255)
    {
      fprintf (stderr, "Very long node `description' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_trie_node_next_level) > 255)
    {
      fprintf (stderr, "Very long node `trie_node_next_level' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_trie_node) > 255)
    {
      fprintf (stderr, "Very long node `trie_node' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_keyword_set) > 255)
    {
      fprintf (stderr, "Very long node `keyword_set' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
  _IR_current_graph_pass_number = 0;
  IR_START_ALLOC ();
}

void IR_stop (void)
{
  IR_STOP_ALLOC ();
}



#line 340 "./ird.sprut"


/* The following function returns external (printable) form of keyword
   representation. */

const char *
keyword_representation (IR_node_t keyword)
{
  if (IR_IS_OF_TYPE (keyword, IR_NM_string_keyword))
    return IR_string_representation (IR_string (keyword));
  else
    return IR_identifier_itself (IR_identifier (keyword));
}

/* The following function returns internal (printable) form of keyword
   representation. */

const char *
keyword_string (IR_node_t keyword)
{
  if (IR_IS_OF_TYPE (keyword, IR_NM_string_keyword))
    return IR_string_itself (IR_string (keyword));
  else
    return IR_identifier_itself (IR_identifier (keyword));
}

/*
Local Variables:
mode:c
End:
*/
