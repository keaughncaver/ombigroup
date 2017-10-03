<!DOCTYPE html>
<!--[if lt IE 7 ]><html class="ie ie6" lang="en"> <![endif]-->
<!--[if IE 7 ]><html class="ie ie7" lang="en"> <![endif]-->
<!--[if IE 8 ]><html class="ie ie8" lang="en"> <![endif]-->
<!--[if (gte IE 9)|!(IE)]><!-->
<html lang="en">
<!--<![endif]-->

<?php

	$path = $_SERVER['REQUEST_URI'] ;
	$sub = "../";

	if ($path === '/') {
		$path = '/home';
	} else {
		$path = rtrim($path, "/");
	}

?>



<?php include 'includes/header.inc';?>


<body class="activateAppearAnimation" id="css/dark-orange.css">

	<div id="globalWrapper" class="localscroll">
	


<?php include 'includes/nav.inc';?>

<?php include "includes".$path.".inc"; ?>

<?php include 'includes/footer.inc';?>



</body>
</html>
