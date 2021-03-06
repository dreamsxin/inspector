/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: krakjoe                                                      |
  +----------------------------------------------------------------------+
*/

/* $Id$ */
#ifndef HAVE_INSPECTOR_ENTRY_H
#define HAVE_INSPECTOR_ENTRY_H

typedef struct _php_inspector_entry_t {
	zend_class_entry *entry;
	zend_object std;
} php_inspector_entry_t;

extern zend_class_entry *php_inspector_entry_ce;

#define php_inspector_entry_fetch_from(o) ((php_inspector_entry_t*) (((char*)o) - XtOffsetOf(php_inspector_entry_t, std)))
#define php_inspector_entry_fetch(z) php_inspector_entry_fetch_from(Z_OBJ_P(z))
#define php_inspector_entry_this() php_inspector_entry_fetch(getThis())

void php_inspector_entry_construct(zval *object, zend_class_entry *ce);

PHP_MINIT_FUNCTION(inspector_entry);
#endif
