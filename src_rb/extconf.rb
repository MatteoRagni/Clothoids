#!/usr/bin/env ruby

require 'mkmf-rice'

$PROJECT_LIB = File.join(Dir.pwd, '../lib')
$PROJECT_INC = File.join(Dir.pwd, '../lib/include')

$APPEND_MAKEFILE = <<MKFL
test: 
\truby test.rb
MKFL

# Custom C++ Flags (required for compatibility with the std c++11)
$CXXFLAGS += " -std=c++11"
$CXXFLAGS += " -Wno-deprecated-register"
$CXXFLAGS += " -Wno-reserved-user-defined-literal"
# Statically adding libClothoids.a to linker
dir_config('Clothoids', $PROJECT_INCLUDE, $PROIJECT_LIB)
$LDFLAGS += " #{File.join $PROJECT_LIB, "libCLothoids.a" }"


create_makefile('G2lib')
if File.exist? "Makefile"
  File.open("Makefile", "a") do |mk|
    mk.puts $APPEND_MAKEFILE
  end
end

