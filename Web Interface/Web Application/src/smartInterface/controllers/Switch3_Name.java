package smartInterface.controllers;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import smartInterface.models.Controller;
import smartInterface.models.JavaClient;

@WebServlet("/rinomina3")
public class Switch3_Name extends HttpServlet {
	private static final long serialVersionUID = 1L;

	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		JavaClient.Send("35");
		Controller.getSwitch3().changeName();
		response.sendRedirect("homePage.jsp");
	}
	
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String sw3 = request.getParameter("sw3");
		JavaClient.Send("31" + sw3);
		Controller.getSwitch3().setName(sw3);
		Controller.getSwitch3().saveName();
		response.sendRedirect("homePage.jsp");
	}
}
