package smartInterface.controllers;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import smartInterface.models.Controller;
import smartInterface.models.JavaClient;

@WebServlet("/rinomina4")
public class Switch4_Name extends HttpServlet {
	private static final long serialVersionUID = 1L;

	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		JavaClient.Send("45");
		Controller.getSwitch4().changeName();
		response.sendRedirect("homePage.jsp");
	}
	
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String sw4 = request.getParameter("sw4");
		JavaClient.Send("41" + sw4);
		Controller.getSwitch4().setName(sw4);
		Controller.getSwitch4().saveName();
		response.sendRedirect("homePage.jsp");
	}
}
