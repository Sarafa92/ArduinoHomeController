package smartInterface.controllers;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import smartInterface.models.Controller;
import smartInterface.models.JavaClient;

@WebServlet("/switch3DIMMER")
public class Switch3_DIMMER extends HttpServlet{
	private static final long serialVersionUID = 1L;

	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		JavaClient.Send("32");
		Controller.getSwitch3().setStatus(1);
		Controller.getSwitch3().setDimmerStatus(Controller.getSwitch3().getDimmerStatus()+1);
		if(Controller.getSwitch3().getDimmerStatus()>3) {
			Controller.getSwitch3().setDimmerStatus(3);
		}
		response.sendRedirect("homePage.jsp");
	} 
	
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		JavaClient.Send("33");
		Controller.getSwitch3().setDimmerStatus(Controller.getSwitch3().getDimmerStatus()-1);
		if(Controller.getSwitch3().getDimmerStatus()<1) {
			Controller.getSwitch3().setStatus(0);
			Controller.getSwitch3().setDimmerStatus(0);
		}
		response.sendRedirect("homePage.jsp");
	}
}
