package smartInterface.controllers;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import smartInterface.models.Controller;
import smartInterface.models.JavaClient;

@WebServlet("/rinomina2")
public class Switch2_Name extends HttpServlet {
	private static final long serialVersionUID = 1L;

	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		JavaClient.Send("25");
		Controller.getSwitch2().changeName();
		response.sendRedirect("homePage.jsp");
	}
	
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String sw2 = request.getParameter("sw2");
		JavaClient.Send("21" + sw2);
		Controller.getSwitch2().setName(sw2);
		Controller.getSwitch2().saveName();
		response.sendRedirect("homePage.jsp");
	}
}
