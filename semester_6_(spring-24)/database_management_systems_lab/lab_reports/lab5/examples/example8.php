<!-- Example 8: while Loop  -->
<?php 
    $widgetsLeft = 10; 
    while ( $widgetsLeft > 0 ) { 
        echo "Selling a widget... "; 
        $widgetsLeft--; 
        echo "done. There are $widgetsLeft widgets left. < br / > "; 
    } 
    echo "We're right out of widgets!"; 
?>