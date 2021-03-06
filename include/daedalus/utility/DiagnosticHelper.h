/*
 * Copyright (C) 2016 Hedede <haddayn@gmail.com>
 *
 * License LGPLv3 or later:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef Daedalus_DignosticHelper
#define Daedalus_DignosticHelper
#include <cassert>
#ifdef _WINDOWS
#include <cstdio>
#endif
#include <iostream> //temporary
#include <aw/utility/string/compose.h>
#include <daedalus/utility/Location.h>
#include <daedalus/utility/Diagnostic.h>
namespace daedalus {
using namespace aw;
struct DiagnosticHelper {
	DiagnosticHelper()
	{
	}

	DiagnosticHelper(SourceBuffer& inputBuffer)
		: buf(&inputBuffer)
	{
	}

	// temporary
	SourceBuffer* buf;

	void report(Diagnostic diag)
	{
		assert(size_t(diag.id) < sizeof(diagMessages)/sizeof(char*));
		auto msg = string::compose(diagMessages[diag.id], diag.args);

		auto pos = countLines(*buf, diag.loc.pos);

		auto line   = pos.first;
		auto column = pos.second;

#ifdef _WINDOWS
		fputs(stderr, compose("error:%0:%1: %2", line, column, msg));
#else
		std::cerr << "error:" << line << ":" << column << ": " << msg << "\n";
#endif
	}
};
} // namespace daedalus
#endif//Daedalus_DignosticHelper
