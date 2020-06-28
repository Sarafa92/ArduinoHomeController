package smartInterface.controllers;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import smartInterface.models.Controller;
import smartInterface.models.JavaClient;

@WebServlet("/switch2DIMMER")
public class Switch2_DIMMER extends HttpServlet{
	private static final long serialVersionUID = 1L;

	@Override 
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		JavaClient.Send("22");
		Controller.getSwitch2().setStatus(1);
		Controller.getSwitch2().setDimmerStatus(Controller.getSwitch2().getDimmerStatus()+1);
		if(Controller.getSwitch2().getDimmerStatus()>3) {
			Controller.getSwitch2().setDimmerStatus(3);
		}
		response.sendRedirect("homePage.jsp");
	}
	
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		JavaClient.Send("23");
		Controller.getSwitch2().setDimmerStatus(Controller.getSwitch2().getDimmerStatus()-1);
		if(Controller.getSwitch2().getDimmerStatus()<1) {
			Controller.getSwitch2().setStatus(0);
			Controller.getSwitch2().setDimmerStatus(0);
		}
		response.sendRedirect("homePage.jsp");
	}
}
