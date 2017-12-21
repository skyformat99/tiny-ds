cmake_minimum_required( VERSION 2.6 )
project( tiny-datastructure )

include_directories( "include" )

# http://blog.csdn.net/xocoder/article/details/8546907
# http://www.cnblogs.com/coderfenghc/archive/2012/07/28/2613567.html

file( GLOB APP_SOURCES src/*.cpp )
foreach( appsourcefile ${APP_SOURCES} )
	get_filename_component( demo_name ${appsourcefile} NAME_WE )
	add_executable( ${demo_name} ${appsourcefile} )
endforeach( appsourcefile ${APP_SOURCES} )
