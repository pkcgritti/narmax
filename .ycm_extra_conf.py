from distutils.sysconfig import get_python_inc
import platform
import os
import ycm_core

# Compilation flags
flags = [
'-Wall',
'-Wextra',
'-Werror',
'-Wno-long-long',
'-Wno-variadic-macros',
'-fexceptions',
'-DNDEBUG',
# Used by YCM Completer
'-DUSE_CLANG_COMPLETER',
# Select language
'-x',
'c++',
'-isystem',
'../BoostParts',
'-isystem',
get_python_inc(),
'-isystem',
'../llvm/include',
'-isystem',
'../llvm/tools/clang/include',
'-I',
'.',
] 

if platform.system() != 'Windows':
    flags.append( '-std=c++11' )

compilation_database_folder = ''

if os.path.exists( compilation_database_folder ):
    database = ycm_core.CompilationDatabase( compilation_database_folder )
else:
    database = None

SOURCE_EXTENSIONS = [ '.cpp', '.cxx', '.cc', '.c', '.m', '.mm' ]

def DirectoryOfThisScript():
    return os.path.dirname( os.path.abspath( __file__ ) )

def IsHeaderFile( filename ):
    extension = os.path.splitext( filename )[ 1 ]
    return extension in [ '.h', '.hxx', '.hpp', '.hh' ]

def GetCompilationInfoForFile( filename ):
    if IsHeaderFile( filename ):
        basename = os.path.splitext( filename )[ 0 ]
        for extension in SOURCE_EXTENSIONS:
            replacement_file = basename + extension
            if os.path.exists( replacement_file ):
                compilation_info = database.GetCompilationInfoForFile(
                    replacement_file )
                if compilation_info.compiler_flags_:
                    return compilation_info
        return None
    return database.GetCompilationInfoForFile( filename )

def FlagsForFile( filename, **kwargs ):
    if not database:
        return {
            'flags': flags,
            'include_paths_relative_to_dir': DirectoryOfThisScript()
        }

    compilation_info = GetCompilationInfoForFile( filename )
    if not compilation_info:
        return None

    final_flags = list( compilation_info.compiler_flags_ )

    try:
        final_flags.remove( '-stdlib=libc++' )
    except ValueError:
        pass

    return {
        'flags': final_flags,
        'include_paths_relative_to_dir': compilation_info.compiler_working_dir_
    }
