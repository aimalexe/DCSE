<!-- Example 11: do-while Loop  -->
<?php 
    $width = 1; 
    $length = 1; 
    do { 
        $width++; 
        $length++; 
        $area = $width * $length; 
    } while ( $area < 1000 ); 
    echo "The smallest square over 1000 sq ft in area is $width ft x $length ft."; 
?> 