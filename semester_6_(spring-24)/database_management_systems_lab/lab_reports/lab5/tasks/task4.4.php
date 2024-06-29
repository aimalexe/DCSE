<!-- When a method in a subclass has the same name, same parameters or signature and same return type (or subtype) as a method in its superclass, then the method in the subclass is said to override the method in the superclass. -->

<?php
class BaseClass {
    public function printMessage() {
        return "This is the BaseClass.";
    }
}

class SubClass extends BaseClass {
    public function printMessage() {
        return "This is the SubClass.";
    }
}

$base = new BaseClass();
$sub = new SubClass();

echo $base->printMessage(); // Outputs: This is the BaseClass.
echo $sub->printMessage();  // Outputs: This is the SubClass.
?>
