/*
 * Auth: ASyS
 *
 * File: Client.java
 *
 * Desc: Rudimentary client program that takes SERVER_IP_ADDRESS and
 *       SERVER_PORT_NUMBER as argument and attempt to connect to them.
 *       Upon successful connection, it reads a single line from its socket
 *       and print them on the STDOUT.
 *
 * Err : Malformed SERVER_IP_ADDRESS causes unknown host exception to
 *       be thrown and the client to exit with code 1. Any error in IO throws
 *       IO exception with exit code 2.
 */
import java.net.*;
import java.io.*;

class Client {
    public static void main(String... args) {
	System.out.println(
	    "Connecting to " + args[0] + ":" + args[1] + "...");
    try {
	Socket socket = new Socket(args[0], Integer.parseInt(args[1]));
	System.out.println(
	    new BufferedReader(
		new InputStreamReader(socket.getInputStream())
	    ).readLine()
	);
	socket.close();
    } catch(UnknownHostException uhe) {
	System.err.println("Unknown host: " + args[0]);
	System.exit(1);
    } catch(IOException ioe) {
	System.err.println("I/O connection failed");
	System.exit(2);
    }
    }
}
