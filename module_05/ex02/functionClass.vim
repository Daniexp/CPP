function! Class(name)
let current_dir = expand('%:p:h')
let folder_name = fnamemodify(current_dir, ':t')
let src_dir = current_dir . "/../src"
let inc_dir = current_dir . "/../inc"
if !isdirectory(src_dir)
	call mkdir(src_dir, 'p')
endif
if !isdirectory(inc_dir)
	call mkdir(inc_dir, 'p')
endif

let src_file = src_dir . "/" . a:name . ".cpp"
let header_file = inc_dir . "/" . a:name . ".hpp"
let src_contents = ["#include <" . a:name . ".hpp>", "", a:name . "::" . a:name . "()", "{", "//Const", "}", "", a:name . "::" . a:name . "(const " . a:name . "& src)", "{", "//Copy Const", "	*this = src;", "}", "", a:name . "::~" . a:name . "()", "{", "//Dest", "}", "", a:name . "& " . a:name . "::operator = (const " . a:name . "& src)", "{", "	return *this;", "}"]
let header_contents = ["#ifndef " . toupper(a:name) . "_H","#define " . toupper(a:name) . "_H","","#include <iostream>","#include <string>","class " . a:name,"{","public:","	" . a:name . "();","	~" . a:name . "();","   " . a:name . "(const " . a:name . "& src);","   " . a:name . "& operator=(const " . a:name . "& src);","private:","","};","","#endif     //" . toupper(a:name) . "_H"]
call writefile(src_contents, src_file)
call writefile(header_contents, header_file)

let dirmake = current_dir . "/../Makefile"
let new_line = "    " . a:name . "\.cpp \"
execute "vsp " . dirmake
call append(12, new_line)
wq

execute "vsp " . current_dir . "/main.cpp"
call append(1, "#include <" . a:name . ".hpp>")
wq!

execute "vsp " . src_file
execute "vsp " . header_file
let &l:modifiable = 1
endfunction
