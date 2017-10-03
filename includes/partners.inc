	<section id="page">
			<header class="page-header">
				<div class="container">
					<div class="row">
						<div class="col-sm-6">
							<h1>Strategic Partners</h1>
						</div>
						<div class="col-sm-6 hidden-xs">
							<ul id="navTrail">
								<li><a href="../">Home</a></li>
								<li id="navTrailLast">Strategic Partners</li>
							</ul>
						</div>
					</div>
				</div>
			</header>
			<section id="content">
				
			






				<!-- logos -->
				<section id="logos" class="color1 pt30 pb30">

					<div class="container">

		<div class="row">
						<div class="span12 text-center mb40">
	
							<h2 class="subTitle">Strategic partners are vital to the success and viability of OMBI Group.  They help to maintain our motto of “Optimum Management Built on Integrity.”  We are very appreciative of the companies that have come on board to help us service our clients.  If you are interested in becoming one of our partners, please <a href="mailto:info@ombigroup.com">click here</a>.</h2>
						</div>
					</div>


						<div class="row mb15">

<?php

$handle = opendir('../images/strategicPartners/');
        while($file = readdir($handle)){
            if($file !== '.' && $file !== '..' && $file != '.DS_Store'){
            
                echo '<div class="col-md-3 col-xs-6 mb15"><img src="../images/strategicPartners/'.$file.'" class="img-responsive imgBorder" alt="clients">	</div>';

            }
        }
?>
						</div>

						
					</div>

				</section>
				<!-- logos -->

			</section>
		</section>