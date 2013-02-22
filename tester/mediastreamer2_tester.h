/*
mediastreamer2 library - modular sound and video processing and streaming
Copyright (C) 2006-2013 Belledonne Communications, Grenoble

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef _MEDIASTREAMER2_TESTER_H
#define _MEDIASTREAMER2_TESTER_H


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__)
#ifdef MEDIASTREAMER2_TESTER_EXPORTS
#define MEDIASTREAMER2_TESTER_EXPORT __declspec(dllexport)
#define MEDIASTREAMER2_TESTER_VAR_EXPORT __declspec(dllexport)
#else
#define MEDIASTREAMER2_TESTER_EXPORT
#define MEDIASTREAMER2_TESTER_VAR_EXPORT extern __declspec(dllimport)
#endif
#else
#define MEDIASTREAMER2_TESTER_EXPORT extern
#define MEDIASTREAMER2_TESTER_VAR_EXPORT extern
#endif


typedef void (*test_function_t)(void);
typedef int (*test_suite_function_t)(const char *name);

typedef struct {
	const char *name;
	test_function_t func;
} test_t;

typedef struct {
	const char *name;
	int nb_tests;
	test_t *tests;
} test_suite_t;


#ifdef __cplusplus
extern "C" {
#endif

MEDIASTREAMER2_TESTER_VAR_EXPORT test_suite_t dtmfgen_test_suite;


MEDIASTREAMER2_TESTER_EXPORT int mediastreamer2_tester_nb_test_suites(void);
MEDIASTREAMER2_TESTER_EXPORT int mediastreamer2_tester_nb_tests(const char *suite_name);
MEDIASTREAMER2_TESTER_EXPORT const char * mediastreamer2_tester_test_suite_name(int suite_index);
MEDIASTREAMER2_TESTER_EXPORT const char * mediastreamer2_tester_test_name(const char *suite_name, int test_index);
MEDIASTREAMER2_TESTER_EXPORT void mediastreamer2_tester_init(void);
MEDIASTREAMER2_TESTER_EXPORT void mediastreamer2_tester_uninit(void);
MEDIASTREAMER2_TESTER_EXPORT int mediastreamer2_tester_run_tests(const char *suite_name, const char *test_name);


#ifdef __cplusplus
};
#endif


#endif /* _MEDIASTREAMER2_TESTER_H */
