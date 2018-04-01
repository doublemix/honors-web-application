<?php
/*	
*	template.inc
*
*	Created by: William Grove:
*	For the global honors program
*	at Lock Haven University of Pennsylvania.
*
*	Created on: 5/16/2016
*/

function HTML_StartHead(){
		echo "<!DOCTYPE html>\n";
		echo "<html>\n";
		echo "<head>\n";
}

function AddTitle( $title ){
		echo "<title>".$title."</title>\n";
}

function AddCSS( $cssfile ){	
	echo "<link href=\"CSS/".$cssfile."\" rel=\"stylesheet\" media=\"screen\">\n";
}

function HTML_EndHead(){
	echo "</head>\n";
}

function HTML_StartBody(){
	echo "<body>\n";
}

function Body_CreateSideNav(){
  echo "<div id=\"mySidenav\" class=\"sidenav\">\n";
  echo "<a href=\"javascript:void(0)\" class=\"closebtn\" onclick=\"closeNav()\">x</a>\n";
  echo "<a href=\"calendar.php\">Calendar</a>\n";		
  echo "<a href=\"#\">Documents</a>\n";		
  if (!isset($_SESSION["username"])){
	echo "<a href=\"login.php\">Login</a>\n";
  } else {
  	if($_SESSION["status"] == 1 || $_SESSION["status"] == 2 || $_SESSION["status"] == 5){
		echo "<a href=\"tools.php\">Tools</a>\n";
  	}
	
	echo "<a href=\"logout.php\" onclick=\"return acceptLogout();\">Log Out</a>\n";
  }
  echo "</div>\n";
}

function Body_CreateHeader( $headertext ){
	echo "<header>\n";
	echo "<img class=\"logo\" src=\"IMG/ghp_logo_second_smaller.png\">\n";
	echo "<h3>".$headertext."</h3>\n";
	echo "</header>\n";
}

function Body_CreateStickyNav(){
	echo "<div id=\"sticky-anchor\"></div>\n";
	echo "<div class=\"menu\" id=\"navbar\">\n";
	echo "<ul class=\"topnav\">\n";
	echo "<li><a class=\"active\" href=\"index.php\">Home</a></li>\n";
	echo "<li><a href=\"calendar.php\">Calendar</a></li>\n";
	echo "<li><a href=\"FreshmanCalendar.php\">Freshman Calendar</a></li>\n";
	echo "<li><a href=\"http://www.lhup.edu/students/global_honors/current_students/ghp_documents.html\">Documents</a></li>\n";
	if (!isset($_SESSION["username"])){
		echo "<li><a href=\"login.php\">Login</a></li>\n";
	} else {
		
		if($_SESSION["status"] == 1 || $_SESSION["status"] == 2 || $_SESSION["status"] == 5){
		echo "<li><a href=\"tools.php\">Tools</a></li>\n";
		echo "<li><a href=\"stats.php\">Stats</a></li>\n";
		}
		
		echo "<li><a href=\"logout.php\">Log out</a></li>\n";
		echo "<div class=\"dropdown-content\">";
		
		if($_SESSION["status"] == 2){
		
		echo "<a href=\"stats.php\">Stats</a>";

		}
		echo "<a href=\"logout.php\" onclick=\"return acceptLogout();\">Log Out</a>\n";
		echo "</div>";
		echo "</li>\n";
  }
	echo "<li class=\"icon\">\n";
    echo "<a href=\"javascript:void(0);\" class=\"icon_button\" onclick=\"openNav()\">&#9776;</a>\n";
	echo "</li>\n";
	echo "</ul>\n";
	echo "</div>\n";
}

function Body_AddScript( $jsfile ){
	echo "<script src=\"JS/".$jsfile."\"></script>\n";
}

function HTML_End(){
    echo "</body>\n";
    echo "</html>";
}

?>