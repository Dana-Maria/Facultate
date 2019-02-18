function inputClick() {
    let inputs = document.getElementsByClassName("choosePath");

    for (let i = 0; i < inputs.length; ++i) {

        inputs[i].addEventListener("click", function() {
            let url = "Pages/" + inputs[i].value.toLowerCase() + ".html";
            window.open(url, "_self");
        }, true);
    }
}

function liClick() {
    let dropdownLis = document.querySelectorAll(".dropdown-menu>li");
    let aInsideLis = document.querySelectorAll(".dropdown-menu>li>a");

    for (let i = 0; i < dropdownLis.length; ++i) {
        dropdownLis[i].addEventListener("click", function() {
            aInsideLis[i].click();
        }, true);
    }
}
