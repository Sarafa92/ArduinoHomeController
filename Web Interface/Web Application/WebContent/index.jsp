<%@ page import="smartInterface.models.JavaClient" %>
<!DOCTYPE html>         
<html lang="it">         
	<head>            
		<meta charset="UTF-8">        
		<link rel="stylesheet" href="style.css" type="text/css" >
		<title>ARDUINO_HOME_CONTROLLER</title>         
	</head>            
	<body>                                   
		<% JavaClient.Connessione(); %>    
		<br><br>   
		<br><br>     
		<div align = "center" id="container"> 
				<h1 align= "center" style="color: white;">~ARDUINO HOME CONTROLLER~</h1>
				<h3 align= "center" style="color: white; font-style: italic">Assegna il nome al tuo controller!</h3>
				<br><br>
				<br><br>
				<form action="homePage" method="post">       
					<input type="text" autocomplete="off" name="controller" required>     
					<input type="submit" value="ASSEGNA" style="color: green">                
				</form>                  
		</div> 
	</body>
 </html>  
