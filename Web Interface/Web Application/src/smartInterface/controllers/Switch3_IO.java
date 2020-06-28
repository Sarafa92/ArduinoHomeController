package smartInterface.controllers;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import smartInterface.models.Controller;
import smartInterface.models.JavaClient;

@WebServlet("/switch3IO")
public class Switch3_IO extends HttpServlet{
	private static final long serialVersionUID = 1L;

	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		JavaClient.Send("34");
		if(Controller.getSwitch3().getStatus()==0) {
			Controller.getSwitch3().setStatus(1);
			Controller.getSwitch3().setDimmerStatus(3);
		}else {
			Controller.getSwitch3().setStatus(0);
			Controller.getSwitch3().setDimmerStatus(0);
		}
		response.sendRedirect("homePage.jsp");
	}
}
