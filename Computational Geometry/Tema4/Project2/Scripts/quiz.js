function generateQuiz() {
    const questions = ["What does sorting a number of elements mean?",
                        "The method that checks every element with all the other elements is: ",
                        "What is the fastest method from the ones learnt in our tutorials?"];

    const answers = [["Ordering them by a criteria", "Finding the maximum", "Counting them"],
                     ["Selection Sort", "Insertion Sort", "Bubble Sort", "Quick Sort"],
                     ["Selection Sort", "Insertion Sort", "Bubble Sort", "Quick Sort"]];

    const correctAnswers = [0, 2, 3];

    const url = window.location.href;
    const splitUrl = url.split("?");

    const currentQuestionIndex = parseInt(splitUrl[1]) - 1;

    let secondsPassed = 0;
    const timer = setInterval(function() {
        secondsPassed++;
        if (secondsPassed === 10) {
            let inputs = document.querySelectorAll("#answers input");
            inputs[correctAnswers[currentQuestionIndex]].style.background = "#007a28";
            inputs[correctAnswers[currentQuestionIndex]].style.color = "#fff";

            clearInterval(timer);
        }

        let spans = document.querySelectorAll("h1>span");
        let currentTime = parseInt(spans[0].textContent);
        currentTime--;
        spans[0].textContent = currentTime + " sec";

    }, 1000);

    let questionSection = document.getElementById("question");
    questionSection.innerHTML = "<p>" + questions[currentQuestionIndex] + "</p>";

    let answerSection = document.getElementById("answers");
    answerSection.innerHTML = "";
    for (let i = 0; i < answers[currentQuestionIndex].length; ++i) {
        let newInput = document.createElement("input");
        newInput.type = "button";
        newInput.value = answers[currentQuestionIndex][i];
        newInput.id = i;

        answerSection.appendChild(newInput);

        newInput.onclick = function() {
            clearInterval(timer);
            if (i === correctAnswers[currentQuestionIndex]) {
                newInput.style.background = "#007a28";
                newInput.style.color = "#fff";
            } else {
                newInput.style.background = "#f00";
                newInput.style.color = "#fff";

                let inputs = document.querySelectorAll("#answers input");
                inputs[correctAnswers[currentQuestionIndex]].style.background = "#007a28";
                inputs[correctAnswers[currentQuestionIndex]].style.color = "#fff";
            }
        }
    }

    let btns = document.querySelectorAll("#nextQuestion input");
    btns[0].onclick = function() {
        const nextQuestionIndex = currentQuestionIndex + 2;
        window.open(splitUrl[0] + "?" + nextQuestionIndex, "_self");
    }

    btns[1].onclick = function() {
        window.open("file:///home/bogdanvm/Desktop/lab_an_2/web/Project2/Pages/quiz.html", "_self");
    }
}

window.onload = function() {
    generateQuiz();
}