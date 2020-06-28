package smartInterface.controllers;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import smartInterface.models.Controller;
import smartInterface.models.JavaClient;

@WebServlet("/switch1IO")
public class Switch1_IO extends HttpServlet{
	private static final long serialVersionUID = 1L;
 
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		JavaClient.Send("14");
		if(Controller.getSwitch1().getStatus()==0) {
			Controller.getSwitch1().setStatus(1);
			Controller.getSwitch1().setDimmerStatus(3);
		}else {
			Controller.getSwitch1().setStatus(0);
			Controller.getSwitch1().setDimmerStatus(0);
		}
		response.sendRedirect("homePage.jsp");
	}
}
