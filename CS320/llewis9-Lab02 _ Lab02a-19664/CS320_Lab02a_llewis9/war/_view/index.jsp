<!DOCTYPE html>

<html>
	<head>
		<title>Simple Calculator</title>
		<script>
    		var sound = new Audio('Marianas.mp3');
			sound.play();
		</script>
		
		<style>
			*{
				margin: 0;
				padding: 0;
			}

			body{
				background-color: black;
				background-image: url('https://media.giphy.com/media/3o6vXTpomeZEyxufGU/giphy.gif');
				background-repeat: no-repeat;
 	 			background-attachment: fixed;
				background-position: 38vw 5vh;
			}

			.container{
				text-align: center;
				margin-left: 39.5%;
				margin-top: 15%;
				width: 25vw;
				border-radius: 50px; 
				background-color: linear-gradient(to bottom right, rgb(254,206,254), rgb(127,30,127), rgb(254,206,254));
			}

			input[type="Submit"]{
				border: none;
				margin-top: 25px;
			}

			input[type="Submit"], legend{
				background-color: rgba(255 , 60, 255, 0.45);
				animation: flash 4s linear 0s infinite forwards;
			}

			input[type="Submit"]:hover{
				background-color: rgba(255 , 60, 255, 1.0);
				border: 2px solid rgba(0, 0, 0, 0.2);
			}

			@keyframes flash{
				00.000% {background-color: rgba(255 , 60, 255, 0.55)}
				12.500% {background-color: rgba(255 , 60, 255, 0.65)}
				25.000% {background-color: rgba(255 , 60, 255, 0.75)}
				37.500% {background-color: rgba(255 , 60, 255, 0.85)}
				50.000% {background-color: rgba(255 , 60, 255, 0.95)}
				62.500% {background-color: rgba(255 , 60, 255, 0.85)}
				75.000% {background-color: rgba(255 , 60, 255, 0.75)}
				87.500% {background-color: rgba(255 , 60, 255, 0.65)}
				100% {background-color: rgba(255 , 60, 255, 0.55)}
			}
			
			#Game{
				margin-top: 10px;
			}

			fieldset{
				border-radius: 50px;
				box-shadow: 10px  ;
			}

			footer{
				color: orange;
			}
		</style>
	</head>

	<body>
		<div class="container">
			<div id="Operations">
			<fieldset>
				<legend>Which operation would you like to perform?</legend>
				<form action="${pageContext.servletContext.contextPath}/addNumbers" method="post">
					<audio src=""></audio>
					<input type="Submit" name="submit" value="Add Numbers!">
				</form>
				<form action="${pageContext.servletContext.contextPath}/subtractNumbers" method="post">
					<input type="Submit" name="submit" value="Subtract Numbers!">
				</form>
				<form action="${pageContext.servletContext.contextPath}/multiplyNumbers" method="post">
					<input type="Submit" name="submit" value="Multiply Numbers!">
				</form>
				<form action="${pageContext.servletContext.contextPath}/divideNumbers" method="post">
					<input type="Submit" name="submit" value="Divide Numbers!">
				</form>	
			</fieldset>
			</div>
			<div id="Game">
				<fieldset>
					<legend>Or are you tired of math and just want to game?<br/> We won't judge &#x1F609</legend>
					<form action="${pageContext.servletContext.contextPath}/guessingGame" method="post">
						<input type="Submit" name="submit" value="Guessing Numbers!">
					</form>
				</fieldset>	
			</div>
		</div>
	</body>
	<footer>
		<div>Background audio track provided by <a href="https://noises.online" title="Noises.Online" target="_blank">Noises.Online</a> under a <a href='http://creativecommons.org/licenses/by/3.0/' title='Creative Commons BY 3.0' target='_blank'>CC 3.0 BY</a> license.</div>
	</footer>
</html>
