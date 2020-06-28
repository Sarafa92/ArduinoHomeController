package smartInterface.controllers;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import smartInterface.models.Controller;
import smartInterface.models.JavaClient;

@WebServlet("/switch1DIMMER")
public class Switch1_DIMMER extends HttpServlet{
	private static final long serialVersionUID = 1L;
 
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		JavaClient.Send("12");
			System.out.println("SONO QUI\n");
		Controller.getSwitch1().setStatus(1);
		Controller.getSwitch1().setDimmerStatus(Controller.getSwitch1().getDimmerStatus()+1);
		if(Controller.getSwitch1().getDimmerStatus()>3) {
			Controller.getSwitch1().setDimmerStatus(3);
		}
		response.sendRedirect("homePage.jsp");
	}
	
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		JavaClient.Send("13");
		
		Controller.getSwitch1().setDimmerStatus(Controller.getSwitch1().getDimmerStatus()-1);
		if(Controller.getSwitch1().getDimmerStatus()<1) {
			Controller.getSwitch1().setStatus(0);
			Controller.getSwitch1().setDimmerStatus(0);
		}
		response.sendRedirect("homePage.jsp");
	}
}
