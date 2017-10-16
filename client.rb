#!/usr/local/bin/ruby23
=begin
Auth: ASyS

File: client.rb

Desc: Rudimentary client program that takes SERVER_IP_ADDRESS and
      SERVER_PORT_NUMBER as argument and attempt to connect to them.
      Upon successful connection, it reads a single line from its socket
      and print them to STDOUT.

Err : Exception is entirely dependent on the interpreter. None is
      handled within this script.
=end

require 'socket'

puts "Connecting to #{ARGV[0]}:#{ARGV[1]}..."
socket = TCPSocket.open ARGV[0], ARGV[1]#Connect to HOST at PORT

puts socket.gets
socket.close
