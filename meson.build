project('linkdemo', 'cpp', default_options : ['cpp_std=c++14'])

boost_dep = dependency('boost', modules : 'system')

common = library('common', 'libcommon.cpp')

client = library('client', 'libclient.cpp',
  link_with : common,
  dependencies : boost_dep)

executable('client', 'client.cpp',
  link_with : client)

server = library('server', 'libserver.cpp',
  link_with : common,
  dependencies : boost_dep)

executable('server', 'server.cpp',
  link_with : server)
