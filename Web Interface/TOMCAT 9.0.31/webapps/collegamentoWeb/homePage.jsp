<%@ page import="smartInterface.models.Switch"
		 import="smartInterface.models.Controller" %>
<!DOCTYPE html>
<html lang="it">
	<head>
		<meta charset="UTF-8">
		<link rel="stylesheet" href="style.css" type="text/css" >
		<title>ARDUINO_HOME_CONTROLLER</title>
	</head>
	<body>
		<br><br>
		<h1 align= "center" style="color: white;">~<%=Controller.getName().toUpperCase()%>~</h1>
		<h3 align= "center" style="color: white; font-style: italic">Gestisci i tuoi dispositivi!</h3>
		<br><br>
		<br><br>
		<div align="center" id="container">
			<form action="switch1IO" method ="post">
				<b><label style="color:white">SWITCH 1: </label></b>
				<% if(Controller.getSwitch1().withName()==0) { %>
					<input type="text" autocomplete="off" name="sw1" required>
					<input type="submit" value="ASSEGNA" formaction="rinomina1" formmethod="post">
					<input type="submit" value="On/Off" disabled>
			 		<input type="submit" value="DIMMER+" disabled>		
			 		<input type="submit" value="DIMMER-" disabled>
			 		<input type="submit" value="RINOMINA" disabled>
			 		
			 	<% }else{ %>
			 		<label style="color: orange; font-weight: bold; font-style: italic;"><%= Controller.getSwitch1().getName().toUpperCase() %></label>
					<input type="submit" value="ASSEGNA" disabled>
					<% if(Controller.getSwitch1().getStatus()==0) { %>
						<input type="submit" value="ACCENDI" formmethod="post" style="color: darkgreen">
					<% }else{ %>
						<input type="submit" value="SPEGNI" formmethod="post" style="color: darkred">
					<% } %>
			 		<input type="submit" value="DIMMER+" formaction="switch1DIMMER" formmethod="post" style="color: black">		
			 		<input type="submit" value="DIMMER-" formaction="switch1DIMMER" formmethod="get" style="color: black">
			 		<input type="submit" value="RINOMINA" formaction="rinomina1" formmethod="get" style="color: teal">
			 	<% } %>
			</form>
			<br><br>
			<form action="switch2IO" method ="post">
				<b><label style="color: white">SWITCH 2: </label></b>
				<% if(Controller.getSwitch2().withName()==0) { %>
					<input type="text" name="sw2" required>
					<input type="submit" value="ASSEGNA" formaction="rinomina2" formmethod="post">
					<input type="submit" value="On/Off" disabled>	
			 		<input type="submit" value="DIMMER+" disabled>		
			 		<input type="submit" value="DIMMER-" disabled>
			 		<input type="submit" value="RINOMINA" disabled>
			 	<% }else{ %>
			 		<label style="color: orange; font-weight: bold; font-style: italic;"><%= Controller.getSwitch2().getName().toUpperCase() %></label>
					<input type="submit" value="ASSEGNA" disabled>
					<% if(Controller.getSwitch2().getStatus()==0) { %>
						<input type="submit" value="ACCENDI" formmethod="post" style="color: darkgreen">
					<% }else{ %>
						<input type="submit" value="SPEGNI" formmethod="post" style="color: darkred">
					<% } %>
			 		<input type="submit" value="DIMMER+" formaction="switch2DIMMER" formmethod="post" style="color: black">		
			 		<input type="submit" value="DIMMER-" formaction="switch2DIMMER" formmethod="get" style="color: black">
			 		<input type="submit" value="RINOMINA" formaction="rinomina2" formmethod="get" style="color: teal">
			 	<% } %>
			</form>
			<br><br>
			<form action="switch3IO" method ="post">
				<b><label style="color: white">SWITCH 3: </label></b>
				<% if(Controller.getSwitch3().withName()==0) { %>
					<input type="text" name="sw3" required>
					<input type="submit" value="ASSEGNA" formaction="rinomina3" formmethod="post">
					<input type="submit" value="On/Off" disabled>	
			 		<input type="submit" value="DIMMER+" disabled>		
			 		<input type="submit" value="DIMMER-" disabled>
			 		<input type="submit" value="RINOMINA" disabled>
			 	<% }else{ %>
			 		<label style="color: orange; font-weight: bold; font-style: italic;"><%=Controller.getSwitch3().getName().toUpperCase()%></label>
					<input type="submit" value="ASSEGNA" disabled>
					<% if(Controller.getSwitch3().getStatus()==0) { %>
						<input type="submit" value="ACCENDI" formmethod="post" style="color: darkgreen">
					<% }else{ %>
						<input type="submit" value="SPEGNI" formmethod="post" style="color: darkred">
					<% } %>
			 		<input type="submit" value="DIMMER+" formaction="switch3DIMMER" formmethod="post" style="color: black">		
			 		<input type="submit" value="DIMMER-" formaction="switch3DIMMER" formmethod="get" style="color: black">
			 		<input type="submit" value="RINOMINA" formaction="rinomina3" formmethod="get" style="color: teal">
			 	<% } %>
			</form>  
			<br><br>
			<form action="switch4IO" method ="post">
				<b><label style="color: white">SWITCH 4: </label></b>
				<% if(Controller.getSwitch4().withName()==0) { %>
					<input type="text" name="sw4" required>
					<input type="submit" value="ASSEGNA" formaction="rinomina4" formmethod="post">
					<input type="submit" value="On/Off" disabled>	
			 		<input type="submit" value="DIMMER+" disabled>		
			 		<input type="submit" value="DIMMER-" disabled>
			 		<input type="submit" value="RINOMINA" disabled>
			 	<% }else{ %>
			 		<label style="color: orange; font-weight: bold; font-style: italic;"><%=Controller.getSwitch4().getName().toUpperCase()%></label>
					<input type="submit" value="ASSEGNA" formmethod="get" disabled>
					<% if(Controller.getSwitch4().getStatus()==0) {%>
						<input type="submit" value="ACCENDI" formmethod="post" style="color: darkgreen">
					<%} else {%>
						<input type="submit" value="SPEGNI" formmethod="post" style="color: darkred">
					<% } %>
			 		<input type="submit" value="DIMMER+" formaction="switch4DIMMER" formmethod="post" style="color: black">		
			 		<input type="submit" value="DIMMER-" formaction="switch4DIMMER" formmethod="get" style="color: black">
			 		<input type="submit" value="RINOMINA" formaction="rinomina4" formmethod="get" style="color: teal">
			 	<%} %>
			</form>
			<br><br>
			<form action = "chiudiSocket" method = "post">
				<input type="submit" value="RINOMINA CONTROLLER" formaction="homePage" formmethod="get" style="color: teal">
				<input type="submit" value="TERMINA CONNESSIONE" formmethod="post" style="color: red">
			</form>
		</div> 
	</body>
</html>
