package smartInterface.controllers;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import smartInterface.models.JavaClient;

@WebServlet("/chiudiSocket")
public class JavaClient_ChiudiSocket_Servlet extends HttpServlet{
	private static final long serialVersionUID = 1L;

		@Override
		protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
			JavaClient.chiusura("QUIT");
			System.exit(0);
		}
}
