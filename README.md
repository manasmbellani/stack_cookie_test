# Stack-Cookie-Test

This is a test app which has a buffer overflow bug that can be bypassed with SEH buffer overflow. The Visual C++ compiled x86 exe has all protections disabled except stack cookies. This can be bypassed with SEH buffer overlfow

# How To crash the app using SEH buffer overflow

Generate a buffer of size 25000 with pattern_create tool in metasploitinto a file and pass the path to this file as an argument to x86 exe binary. If debugging via immunity debugger, you can view the seh chain and see the overwrites

