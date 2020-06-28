package smartInterface.models;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

public abstract class JavaClient {
	
	 static Socket socket = null;
	 static BufferedReader in = null;
	 static PrintStream out = null;
	 static String receive = null;

	public static void Connessione() {
		 
		//creazione socket
		try{
			socket = new Socket("127.0.0.1", 1234);
			System.out.println("Socket Avviata!");
			//Creazione degli stream di input e output 
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			out = new PrintStream(socket.getOutputStream(), true);
			
		}catch(Exception e) { 
			System.out.println(e.getMessage());
		}
	}  
	
	public static void chiusura(String str) {
		
			Send(str);
			try {
				socket.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
	}
	
	public static void Send(String str) {
		
		try {
			//PrintStream output = null;
			out = new PrintStream(socket.getOutputStream(), true);
			//TimeUnit.SECONDS.sleep(1);
			out.println(str);
			//output.flush();
		}
		catch(Exception e) {
			System.out.println("Errore durante la comunicazione con la porta: " + e);
		}
	}
	
	
}
