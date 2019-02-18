function generatePage() {
    const url = window.location.href;
    const splitUrl = url.split("?");

    const params = splitUrl[1].split("&");

    let contentByPage = {};
    contentByPage["SortIntroduction"] = "<h1>Sorting Algorithms </h1>" +
        "<div> <p>A Sorting Algorithm is used to rearrange a given array or list elements according to a comparison\n" +
        "operator on the elements. The comparison operator is used to decide the new order of element in the\n" +
        "respective data structure.</p> " +
        "<p> For example: The below list of characters is sorted in increasing order of their ASCII values.\n" +
        "That is, the character with lesser ASCII value will be placed first than\n" +
        "the character with higher ASCII value.</p><p class=\"imageLesson\"> <span> blablapro</span> =>" +
        "<span>aabbllopr </span> " + "</p>";

    contentByPage["SortBubble"] = "<h1>Bubble Sort </h1>" +
        "<div> <p>Bubble Sort is the simplest sorting algorithm that works " +
        "by repeatedly swapping the adjacent elements if they are in wrong order." +
        "<p class='imageLesson'> <span>( <span id='redSpan'>5</span> <span id='redSpan'>1</span> 4 2 8 )</span> –> " +
        "<span>( <span id='greenSpan'>1</span> <span id='greenSpan'> 5</span> 4 2 8 )</span>, " +
        "Swap since 5 > 1.</p>" +
        "<p class='imageLesson'> <span>( 1 <span id='redSpan'>5</span> <span id='redSpan'>4</span> 2 8 )</span> –> " +
        "<span>( 1 <span id='greenSpan'>4</span> <span id='greenSpan'>5 </span> 2 8 )</span>, " +
        "Swap since 5 > 4</p>" + "<p class='imageLesson'> <span>( 1 4 <span id='redSpan'>5</span> <span id='redSpan'>2</span> 8 )" +
        "</span> –> <span>( 1 4 <span id='greenSpan'> 2 </span> <span id='greenSpan'> 5 </span> 8 )</span>, " +
        "Swap since 5 > 2</p>" + "<p class='imageLesson'> <span>( 1 4 2 5 8 )</span> –> <span>( 1 4 2 5 8 )</span>, " +
        "5 == 2, so no swap</p>" + "<p> These steps continue foreach element, until the vector is sorted. </p>";

    const myPage = params[0] + params[1];
    let mainContent = document.getElementById("explanations");

    if (contentByPage[myPage] === undefined) {
        mainContent.innerHTML = "<p>We are currently working on this page. Stay tuned for updates</p>"
    } else {
        mainContent.innerHTML = contentByPage[myPage];
    }

    let pageOrder = ["SortIntroduction", "SortBubble", "SortSelection", "SortInsertion", "SortQsort"];
    let currentPage = pageOrder.indexOf(myPage);
    if (currentPage !== -1) {
        if (currentPage === 0) {
            let prevBtn = document.getElementById("previousBtn");
            let nextBtn = document.getElementById("nextBtn");

            prevBtn.value = "ALGORITHMS";
            nextBtn.value = "BUBBLE SORT";

            prevBtn.onclick = function() {
                window.open("file:///home/bogdanvm/Desktop/lab_an_2/web/Project2/Pages/algorithms.html", "_self");
            }

            nextBtn.onclick = function() {
                window.open("file:///home/bogdanvm/Desktop/lab_an_2/web/Project2/Pages/genericAlgPage.html?Sort&Bubble",
                    "_self");
            }
            return;
        }

        const camelSplitPrev = pageOrder[currentPage - 1].replace(/([a-z])([A-Z])/, "$1 $2");
        const camelSplitNext = pageOrder[currentPage + 1].replace(/([a-z])([A-Z])/, "$1 $2");

        let prevBtn = document.getElementById("previousBtn");
        let nextBtn = document.getElementById("nextBtn");

        const pageKeyWordsPrev = camelSplitPrev.split(" ");
        const pageKeyWordsNext = camelSplitNext.split(" ");

        prevBtn.value = pageKeyWordsPrev[1].toUpperCase() + " " + pageKeyWordsPrev[0].toUpperCase();
        nextBtn.value = pageKeyWordsNext[1].toUpperCase() + " " + pageKeyWordsNext[0].toUpperCase();

        prevBtn.onclick = function() {
            window.open(splitUrl[0] + "?" + pageKeyWordsPrev[0] + "&" + pageKeyWordsPrev[1], "_self");
        }

        nextBtn.onclick = function() {
            window.open(splitUrl[0] + "?" + pageKeyWordsNext[0] + "&" + pageKeyWordsNext[1], "_self");
        }
    }
}

window.onload = function() {
    generatePage();
    liClick();
}