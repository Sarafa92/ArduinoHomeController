package smartInterface.controllers;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import smartInterface.models.Controller;
import smartInterface.models.JavaClient;
	
@WebServlet("/rinomina1")
public class Switch1_Name extends HttpServlet {
	private static final long serialVersionUID = 1L;

	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		JavaClient.Send("15");
		Controller.getSwitch1().changeName();
		response.sendRedirect("homePage.jsp");
	}
	
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String sw1 = request.getParameter("sw1");
		JavaClient.Send("11" + sw1);
		Controller.getSwitch1().setName(sw1);
		Controller.getSwitch1().saveName();
		response.sendRedirect("homePage.jsp");
	}
}
