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
#include <iostream> //temporary
#include <daedalus/utility/string.h>
#include <daedalus/utility/Diagnostic.h>
namespace daedalus {
class DiagnosticHelper {
public:
	DiagnosticHelper()
	{
	}

	void report(Diagnostic diag)
	{
		auto msg = string::compose(
		             getDiagMsg(diag.id), diag.args);
		std::cerr << msg << "\n";
	}
};
} // namespace daedalus
#endif//Daedalus_DignosticHelper