function toggleDisplay(hiddenDiv, arrow) {
    let displayValue = window.getComputedStyle(hiddenDiv, null).getPropertyValue("display");
    let currentIcon = arrow.childNodes[1];

    if (displayValue.localeCompare("none") === 0) {
        hiddenDiv.style.display = "block";
        currentIcon.className = "fa fa-angle-up";
    } else {
        hiddenDiv.style.display = "none";
        currentIcon.className = "fa fa-angle-down";
    }
}

function toggleOnArrowClick() {
    let arrows = document.querySelectorAll(".visible>span");
    let hiddenDivs = document.getElementsByClassName("hidden");

    for (let i = 0; i < arrows.length; ++i) {
        arrows[i].addEventListener("click", function() {
            toggleDisplay(hiddenDivs[i], arrows[i]);
        }, true);
    }
}

function goToTopic() {
    let arrows = document.querySelectorAll(".visible>span");
    let lessons = document.getElementsByClassName("goToLesson");

    for (let i = 0; i < lessons.length; ++i) {
        lessons[i].addEventListener("click", function() {
            arrows[i].click();
        }, true);
    }
}
