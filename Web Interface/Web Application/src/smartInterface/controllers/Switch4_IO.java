package smartInterface.controllers;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import smartInterface.models.Controller;
import smartInterface.models.JavaClient;

@WebServlet("/switch4IO")
public class Switch4_IO extends HttpServlet{
	private static final long serialVersionUID = 1L;

	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		JavaClient.Send("44");
		if(Controller.getSwitch4().getStatus()==0) {
			Controller.getSwitch4().setStatus(1);
			Controller.getSwitch4().setDimmerStatus(3);
		}else {
			Controller.getSwitch4().setStatus(0);
			Controller.getSwitch4().setDimmerStatus(0);
		}
		response.sendRedirect("homePage.jsp");
	}
}
