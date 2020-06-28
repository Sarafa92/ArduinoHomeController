package smartInterface.controllers;

 
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import smartInterface.models.Controller;
import smartInterface.models.JavaClient;

@WebServlet("/homePage")
public class Controller_Name extends HttpServlet{ 
	private static final long serialVersionUID = 1L;
	 
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String controllerName = request.getParameter("controller");
			JavaClient.Send("00" + controllerName);
			//aspetto ack dal pc (FATTO)
			
			Controller.setName(controllerName);
		    response.sendRedirect("homePage.jsp");
	}
	
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		JavaClient.Send("01");
		response.sendRedirect("controllerRename.jsp");
	}
}
