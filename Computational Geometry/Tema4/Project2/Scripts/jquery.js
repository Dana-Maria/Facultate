$(document).ready(function() {
    $(".blurredImg").hide(0).fadeIn("slow");
    $(".nav-item-dropdown").hover(
        function() {
            $(".dropdown-menu").stop(true, true).delay(200).fadeIn(200);
        },
        function() {
            $(".dropdown-menu").stop(true, true).delay(200).fadeOut(200);
        }
    );

    $("#categories").hide(0).fadeIn("slow");
    $(".lessons").hide(0).fadeIn("slow");
    $(".stickyFooter").hide(0).fadeIn("slow");
    $(".navbar").hide(0).fadeIn("slow");
});
