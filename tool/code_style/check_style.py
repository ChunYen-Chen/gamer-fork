import re
import os



#====================================================================================================
# Constants
#====================================================================================================
# { style_name: [ wrong_style_pattern, fix_style_pattern, search_pattern_inVim ] }
ALL_STYLE  = { "trailing_space"  :[ r'\s+\n',                                      r'\n',               r'\s\+$'     ] }
CODE_STYLE = { "start_comment"   :[ r'^\s+//',                                     r'//' ,              r'^\s\+\/\/' ],
               "tab"             :[ r'\t',                                         r'   ',              r'\t'        ],
               "start_preprocess":[ r'^\s+\#',                                     r'#',                r'^\s\+\#'   ]
#               TODO: Can not ignore the comma in string, need to find a solution
#               "comma"           :[ r',([^\s^\n])',                                r', \1',             r',[^ \n]'   ]
             }
WIKI_STYLE = { "tab"             :[ r'\t',                                         r'   ',              r'\t'        ] }

DRY_RUN = True

# get all files
ALL_FILES = []
for dir_path, dir_names, file_names in os.walk("../../"):
    if file_names == []: continue

    if "/.git"                    in dir_path: continue
    if "/.github"                 in dir_path: continue
    if "/.vscode"                 in dir_path: continue
    if "/.DS_Store"               in dir_path: continue
    if "/bin"                     in dir_path: continue
    if "/test_problem_deprecated" in dir_path: continue
    if "/doc/wiki/images"         in dir_path: continue
    if "/src/Object"              in dir_path: continue

    for file_name in file_names:
        if file_name in ["gamer", ".empty", "GAMER_CompareData", "GAMER_ExtractUniform", "GAMER_ExtractProfile", "Makefile", "Makefile.log"]: continue
        ALL_FILES.append( os.path.join( dir_path, file_name ) )

CODE_FILES = []
for dir_path, dir_names, file_names in os.walk("../../src"):
    if file_names == []: continue
    for file_name in file_names:
        if ".cpp" not in file_name: continue
        CODE_FILES.append( os.path.join( dir_path, file_name ) )

for dir_path, dir_names, file_names in os.walk("../../include"):
    if file_names == []: continue
    for file_name in file_names:
        if ".h" not in file_name: continue
        CODE_FILES.append( os.path.join( dir_path, file_name ) )

WIKI_FILES = []
for dir_path, dir_names, file_names in os.walk("../../doc/wiki"):
    if file_names == []: continue
    for file_name in file_names:
        if ".md" not in file_name: continue
        WIKI_FILES.append( os.path.join( dir_path, file_name ) )




#====================================================================================================
# Functions
#====================================================================================================
def check_style( file_names, styles, output ):
    status = True

    for file_name in file_names:
        with open( file_name, 'r' ) as f:
            lines = f.readlines()

        passed     = True
        fail_count = { i:0 for i in styles }
        for name, style in styles.items():
            for i, line in enumerate(lines):
                temp, n = re.subn( style[0], style[1], line )
                if n == 0: continue
                if temp == lines[i]: continue

                # check indent before this line
                if DRY_RUN:
                    print("At %d"%(i+1))
                    print("Old: %s"%lines[i][:-1])
                    print("===> %s"%temp[:-1])
                lines[i] = temp
                fail_count[name] += n

            if fail_count[name] != 0:
                passed = False
                status = False

        if passed: continue

        print( "%-100s fail"%file_name )
        print( ", ".join( [ "%s => Found %d"%(name, fail_count[name]) for name in styles if fail_count[name] != 0 ] ) )

        if not output: continue

        with open( file_name, 'w' ) as f:
            for line in lines:
                f.write( line )

    return status



#====================================================================================================
# Main
#====================================================================================================
if __name__ == "__main__":
    check_style(  ALL_FILES,  ALL_STYLE, False )
    check_style( CODE_FILES, CODE_STYLE, False )
    check_style( WIKI_FILES, WIKI_STYLE, False )
