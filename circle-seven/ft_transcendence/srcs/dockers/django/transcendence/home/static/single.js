function loadTabS() {
    let lastCheck = 0;
    const checkInterval = 1000;
    let delta = 0;
    let mapevent = 0;
    let sixpos = "";
    let ballDirection = "";
    let savedBall = { pos: { x: 0, y: 0 }, velocity: { x: 0, y: 0 } };
    let tolerance = 0;
    flag_history = false;
    const canvas = document.getElementById("canvas");
    const ctx = canvas.getContext('2d');
    const player2Score = document.getElementById("player2Score");
    const player1Score = document.getElementById("player1Score");
    const usernamePlayer = document.getElementById('usernameSingle');
    const usernameBot = document.getElementById('usernameBot');
    const gameOverModal = document.querySelector('.game-over-modal');
    const startGameModal = document.querySelector('.start-game-modal');
    const increasePaddlePace = document.querySelector('.increase-paddle-pace');
    const decreasePaddlePace = document.querySelector('.decrease-paddle-pace');
    const increaseBallPace = document.querySelector('.increase-ball-pace');
    const decreaseBallPace = document.querySelector('.decrease-ball-pace');
    const decreaseScoreBtn = document.querySelector('.decrease-score-btn');
    const increaseScoreBtn = document.querySelector('.increase-score-btn');
    let ballPaceValue = document.querySelector('.ball-pace-value');
    let paddlePaceValue = document.querySelector('.paddle-pace-value');
    let newScore = document.querySelector('.new-score-count');
    let newScoreDisplay = document.querySelector('#newScoreDisplay');
    const changeMap1 = document.querySelector('.btn-map1');
    const changeMap2 = document.querySelector('.btn-map2');
    const changeMap3 = document.querySelector('.btn-map3');
    const changeMap4 = document.querySelector('.btn-map4');


    canvas.width = 1100;
    canvas.height = 600;

    let gameOver = false;
    let gameStarted = false;
    let winner = '';


    newScoreDisplay.textContent = newScore.textContent;

    keysPressed = [];
    function keyDownHandler(e) {
        keysPressed[e.key] = true;
    }

    function keyUpHandler(e) {
        keysPressed[e.key] = false;
    }
    window.addEventListener('keydown', keyDownHandler);
    window.addEventListener('keyup', keyUpHandler);

    function vec2(x, y) {
        return { x: x, y: y };
    }

    function Ball(pos, velocity, radius) {
        this.pos = pos;
        this.velocity = velocity;
        this.radius = radius;

        this.update = function () {
            this.pos.x += this.velocity.x;
            this.pos.y += this.velocity.y;

        };
        this.draw = function () {
            ctx.fillStyle = "#fff";
            ctx.strokeStyle = "#fff";
            ctx.beginPath();
            ctx.arc(this.pos.x, this.pos.y, this.radius / 2, 0, Math.PI * 2);
            ctx.fill();
            ctx.stroke();
        };


    }

    function Paddle(pos, velocity, width, height) {
        this.pos = pos;
        this.velocity = velocity;
        this.width = width;
        this.height = height;
        this.score = 0;

        this.update = function () {
            if (keysPressed['w'])
                paddle1.pos.y -= paddle1.velocity.y;
            if (keysPressed['s'])
                paddle1.pos.y += paddle1.velocity.y;
        }

        this.draw = function () {
            ctx.fillStyle = "#fff";
            ctx.fillRect(this.pos.x, this.pos.y, this.width, this.height);
        };
        this.getHalfWidth = function () {
            return this.width / 2;
        };
        this.getHalfHeight = function () {
            return this.height / 2;
        };
        this.getCenter = function () {
            return vec2(this.pos.x + this.getHalfWidth(), this.pos.y + this.getHalfHeight());
        }
    }



    function paddleCollisionWithTheEdges(paddle) {
        if (paddle.pos.y <= 0)
            paddle.pos.y = 0;
        if (paddle.pos.y + paddle.height >= canvas.height)
            paddle.pos.y = canvas.height - paddle.height;
    }


    function ballCollisionWithTheEdges(ball) {
        if (ball.pos.y + ball.radius >= canvas.height) //bottom wall
        {
            ball.velocity.y *= -1;
        }
        if (ball.pos.y - ball.radius <= 0) //top wall
        {
            ball.velocity.y *= -1;
        }

    }


    function respawnBall(ball) {
        if (ball.velocity.x > 0) {
            ball.pos.x = canvas.width - 150;
            ball.pos.y = (Math.random() * (canvas.height - 200)) + 100;
        }
        if (ball.velocity.x < 0) {
            ball.pos.x = 150;
            ball.pos.y = (Math.random() * (canvas.height - 200)) + 100;
        }
        ball.velocity.x *= -1;
        ball.velocity.y *= -1;
    }

    function increaseScore(ball, paddle1, paddle2) {

        if (ball.pos.x <= ball.radius) {
            paddle2.score += 1;
            player2Score.innerHTML = paddle2.score;
            respawnBall(ball);
        }
        if (ball.pos.x >= canvas.width - ball.radius) {
            paddle1.score += 1;
            player1Score.innerHTML = paddle1.score;
            lastCheck = 0;
            respawnBall(ball);
        }
        if (paddle1.score === newScoreValue || paddle2.score === newScoreValue) {
            gameOver = true;
            winner = paddle1.score === newScoreValue ? usernamePlayer.textContent : usernameBot.textContent;
        }
        if (paddle1.score >= newScoreValue || paddle2.score >= newScoreValue) {
            setTimeout(() => {
                if (paddle1.score >= newScoreValue) {
                    showGameOverModal(paddle1);
                } else if (paddle2.score >= newScoreValue) {
                    showGameOverModal(paddle2);
                }
            }, 100);
        }


    }


    function ballPaddleCollision(ball, paddle) {
        let dx = ball.pos.x - paddle.getCenter().x;
        let dy = ball.pos.y - paddle.getCenter().y;

        let halfPaddleWidth = paddle.getHalfWidth();
        let halfPaddleHeight = paddle.getHalfHeight();
        let overlapX = ball.radius + halfPaddleWidth - Math.abs(dx);
        let overlapY = ball.radius + halfPaddleHeight - Math.abs(dy);

        if (overlapX > 0 && overlapY > 0) {
            // Resolve collision based on the smaller overlap
            if (overlapX < overlapY) {
                // Ball collided horizontally
                ball.velocity.x *= -1;
                // Adjust ball position to avoid overlap
                ball.pos.x += (dx > 0 ? overlapX : -overlapX);
            } else {
                // Ball collided vertically
                ball.velocity.y *= -1;
                // Adjust ball position to avoid overlap
                ball.pos.y += (dy > 0 ? overlapY : -overlapY);
            }
        }
    }

    // IA gameplay

    function determineSixpos(saveball) {
        if (saveball.pos.x < canvas.width / 2 && saveball.pos.y < canvas.height * 0.33) {
            return "high-left";
        }
        else if (saveball.pos.x > canvas.width / 2 && ball.pos.y < canvas.height * 0.33)
            return "high-right";
        else if (saveball.pos.x < canvas.width / 2 && saveball.pos.y > canvas.height * 0.33 && saveball.pos.y < canvas.height * 0.66)
            return "middle-left";
        else if (saveball.pos.x > canvas.width / 2 && saveball.pos.y > canvas.height * 0.33 && saveball.pos.y < canvas.height * 0.66)
            return "middle-right";
        else if (saveball.pos.x < canvas.width / 2 && saveball.pos.y > canvas.height * 0.66)
            return "down-left";
        else if (saveball.pos.x > canvas.width / 2 && saveball.pos.y > canvas.height * 0.66)
            return "down-right";
        else
            return "middle";
    }
    function determineBallDirection(saveball, currentpos) {
        if (saveball.pos.x < currentpos)
            return "ia";
        else
            return "joueur";

    }

    function gotomiddle(paddle, sixpos, ballDirection, tolerance) {
        if (paddle.pos.y + paddle.height / 2 < canvas.height * 0.33 + tolerance) {
            paddle.pos.y += paddle.velocity.y;
        }
        else if (paddle.pos.y + paddle.height / 2 > canvas.height * 0.66 + tolerance) {
            paddle.pos.y -= paddle.velocity.y;
        }
        else {
            if (paddle.pos.y + paddle.height / 2 < canvas.height * 0.33 + tolerance) {
                paddle.pos.y -= paddle.velocity.y;
            }
        }
    }


    function player2AI(ball, paddle, currentT) {
        // 1 sec clock
        if (lastCheck === 0) {
            savedBall = {
                pos: { x: ball.pos.x, y: ball.pos.y },
                velocity: { x: ball.velocity.x, y: ball.velocity.y }
            };
            tolerance = paddle.height * 0.1;
            lastCheck = currentT;
        }
        delta = currentT - lastCheck;
        if (delta > checkInterval) {
            lastCheck = currentT;
            tolerance = tolerance * 1.05;
            sixpos = determineSixpos(savedBall);
            ballDirection = determineBallDirection(savedBall, ball.pos.x);
            savedBall = {
                pos: { x: ball.pos.x, y: ball.pos.y },
                velocity: { x: ball.velocity.x, y: ball.velocity.y }
            };

        }
        if (ballDirection === "joueur") {
            gotomiddle(paddle, sixpos, ballDirection, tolerance);
        }
        else {
            if (savedBall) {
                // Calculer le temps estimé avant que la balle n'atteigne la raquette de l'IA
                let timeToReachPaddle = (paddle.pos.x - savedBall.pos.x) / savedBall.velocity.x;

                // Prédire la position future de la balle sur l'axe Y
                let predictedY = savedBall.pos.y + savedBall.velocity.y * timeToReachPaddle;

                // Gérer les rebonds sur les murs supérieurs et inférieurs
                while (predictedY < 0 || predictedY > canvas.height) {
                    if (predictedY < 0) {
                        predictedY = -predictedY;
                    } else if (predictedY > canvas.height) {
                        predictedY = 2 * canvas.height - predictedY;
                    }
                }
                // Calculer le centre du paddle
                let paddleCenter = paddle.pos.y + paddle.height / 2;
                //Deplace le paddle vers la position de la prediction
                if (paddleCenter < predictedY - tolerance) {
                    paddle.pos.y += paddle.velocity.y;
                    if (paddle.pos.y + paddle.height >= canvas.height)
                        paddle.pos.y = canvas.height - paddle.height;
                } else if (paddleCenter > predictedY + tolerance) {
                    paddle.pos.y -= paddle.velocity.y;
                    if (paddle.pos.y <= 0)
                        paddle.pos.y = 0;
                }
            }
        }
        if (paddle.pos.y <= 0)
            paddle.pos.y = 0;
        if (paddle.pos.y + paddle.height >= canvas.height)
            paddle.pos.y = canvas.height - paddle.height;
    }

    function valid_change_map() {
        if (gameOver || !gameStarted)
            return true;
        else
            return false;
    }

    function resetMapClasses() {
        canvas.classList.remove('class-map2', 'class-map3', 'class-map4'); // Remove all map-related classes
    }
    const colors = ['#a9a9a9', '#add8e6', '#20b2aa'];
    let colorIndex = 0;
    changeMap1.addEventListener('click', function () {
        if (valid_change_map()) {
            canvas.style.backgroundColor = colors[colorIndex];
            colorIndex = (colorIndex + 1) % colors.length;
            resetMapClasses();
            mapevent = 0;
        }
    });

    changeMap2.addEventListener('click', function () {
        if (valid_change_map()) {
            resetMapClasses();
            canvas.classList.add('class-map2');
            canvas.style.backgroundColor = "";
            mapevent = 1;
        }
    });
    changeMap3.addEventListener('click', function () {
        if (valid_change_map()) {
            resetMapClasses();
            canvas.classList.add('class-map3');
            canvas.style.backgroundColor = "";
            mapevent = 2;
        }
    });
    changeMap4.addEventListener('click', function () {
        if (valid_change_map()) {
            resetMapClasses();
            canvas.classList.add('class-map4');
            canvas.style.backgroundColor = "";
            mapevent = 3;
        }
    });

    function drawGameScene() {
        ctx.strokeStyle = "#fff";

        ctx.beginPath();
        ctx.lineWidth = 8;
        ctx.moveTo(canvas.width / 2, 0);
        ctx.lineTo(canvas.width / 2, canvas.height);
        ctx.stroke();

    }

    const paddleMargin = 5;
    const ball = new Ball(vec2(200, 200), vec2(5, 5), 20);
    const paddle1 = new Paddle(vec2(paddleMargin, 50), vec2(5, 5), 20, 160);
    const paddle2 = new Paddle(vec2(canvas.width - paddleMargin - 20, 30), vec2(5, 5), 20, 160);
    let paddle1VelocityChange = vec2(10, 10);
    let paddle2VelocityChange = vec2(10, 10);
    let paddleVelocity = 10;

    // Paddle velocity limit
    decreasePaddlePace.addEventListener('click', function () {
        if ((gameOver || !gameStarted) && (paddleVelocity > 1)) {
            paddle1VelocityChange.x -= 1;
            paddle1VelocityChange.y -= 1;
            paddle2VelocityChange.x -= 1;
            paddle2VelocityChange.y -= 1;
            paddleVelocity--;
            paddlePaceValue.textContent = paddleVelocity;
        }
    });
    increasePaddlePace.addEventListener('click', function () {
        if ((gameOver || !gameStarted) && (paddleVelocity < 15)) {
            paddle1VelocityChange.x += 1;
            paddle1VelocityChange.y += 1;
            paddle2VelocityChange.x += 1;
            paddle2VelocityChange.y += 1;
            paddleVelocity++;
            paddlePaceValue.textContent = paddleVelocity;
        }
    });

    // Ball velocity limit

    let velocityChange = vec2(10, 10);
    let velocity = 10;

    increaseBallPace.addEventListener('click', function () {
        if ((gameOver || !gameStarted) && velocity < 15) {
            velocityChange.x += 1;
            velocityChange.y += 1;
            velocity++;
            ballPaceValue.textContent = velocity;
        }
    });
    decreaseBallPace.addEventListener('click', function () {
        if ((gameOver || !gameStarted) && velocity > 1) {
            velocityChange.x -= 1;
            velocityChange.y -= 1;
            velocity--;
            ballPaceValue.textContent = velocity;
        }
    });

    // Score limit
    decreaseScoreBtn.addEventListener('click', function () {
        let currentScore = parseInt(newScore.textContent);
        if ((gameOver || !gameStarted) && currentScore > 1) {
            currentScore--;
            newScoreValue = currentScore;
            newScore.textContent = currentScore;
            newScoreDisplay.textContent = currentScore;
        }
    });
    let newScoreValue = parseInt(newScore.textContent);

    increaseScoreBtn.addEventListener('click', function () {
        let currentScore = parseInt(newScore.textContent);
        if ((gameOver || !gameStarted) && currentScore < 20) {
            currentScore++;
            newScoreValue = currentScore;
            newScore.textContent = currentScore;
            newScoreDisplay.textContent = currentScore;
        }
    });


    function gameUpdate() {
        currentT = Date.now();
        ball.update();
        paddle1.update();
        paddleCollisionWithTheEdges(paddle1);
        ballCollisionWithTheEdges(ball);
        player2AI(ball, paddle2, currentT);
        ballPaddleCollision(ball, paddle1);
        ballPaddleCollision(ball, paddle2);
        GameEvent();
        increaseScore(ball, paddle1, paddle2);

    }

    function gameDraw() {
        ball.draw();
        paddle1.draw();
        paddle2.draw();
        drawGameScene();

    }

    function GameEvent() {
        switch (mapevent) {
            case 1:
                // Car: Augmente la vitesse de la balle
                if (ball.pos.x > canvas.width / 3 && ball.pos.x < 2 * canvas.width / 3) {
                    if (Math.random() < 0.01 && !ball.speedBoostActive) {
                        ball.velocity.x *= 1.5;
                        ball.velocity.y *= 1.5;
                        ball.speedBoostActive = true;
                        setTimeout(() => {
                            ball.velocity.x /= 1.5;
                            ball.velocity.y /= 1.5;
                            ball.speedBoostActive = false;
                        }, 500);
                    }
                }
                break;
            case 2:
                // Rain: fait tomber plus vite la balle si elle est dans le 1/3 supérieur de l'écran
                if (ball.pos.x > canvas.width / 3 && ball.pos.x < 2 * canvas.width / 3) {
                    if (Math.random() < 0.01) {
                        if (ball.pos.y < canvas.height * 0.33 && !ball.fallActive) {
                            ball.velocity.y *= 1.5;
                            ball.fallActive = true;

                            let interval = setInterval(() => {
                                // Si la balle atteint le 1/3 inférieur de l'écran ou la direction change
                                if (ball.pos.y > canvas.height * 0.66 || ball.velocity.y < 0) {
                                    ball.velocity.y /= 1.5;
                                    ball.fallActive = false;
                                    clearInterval(interval);
                                }
                                else if (ball.velocity.y < 1) {
                                    ball.velocity.y = 1;
                                }
                            }, 50);
                            setTimeout(() => {
                                if (ball.fallActive) {
                                    ball.velocity.y /= 2.5;
                                    if (ball.velocity.y < 1) ball.velocity.y = 14;
                                    ball.fallActive = false;
                                    clearInterval(interval);
                                }
                            }, 500);
                        }
                    }
                }
                break;
            case 3:
                // Cat: Rediriger la balle de manière aléatoire si elle est dans le tiers central du canvas
                if (ball.pos.x > canvas.width / 3 && ball.pos.x < 2 * canvas.width / 3) {
                    if (Math.random() < 0.01) {
                        let randomFactorX = (Math.random() * 2 - 1) * 5;
                        let randomFactorY = (Math.random() * 2 - 1) * 5;
                        ball.velocity.x += randomFactorX;
                        ball.velocity.y += randomFactorY;
                        const maxVelocity = 15;
                        const currentSpeed = Math.sqrt(ball.velocity.x ** 2 + ball.velocity.y ** 2);
                        if (currentSpeed > maxVelocity) {
                            ball.velocity.x = (ball.velocity.x / currentSpeed) * maxVelocity;
                            ball.velocity.y = (ball.velocity.y / currentSpeed) * maxVelocity;
                        }
                    }
                }
                break;
        }

    }
    function gameLoop() {
        window.addEventListener('blur', function () {
            keysPressed = [];
        });
        if (!gameOver) {
            ctx.clearRect(0, 0, canvas.width, canvas.height);
            gameUpdate();
            gameDraw();
            window.requestAnimationFrame(gameLoop);
        } else {
            deactiveGameMove();
            showGameOverModal();
        }

    }
    function deactiveGameMove() {
        document.removeEventListener("keydown", keyDownHandler);
        document.removeEventListener("keyup", keyUpHandler);
    }
    function showGameOverModal() {
        if (window.location.pathname.includes("game/single")) {
            gameOverModal.classList.remove('d-none');
            gameOverModal.classList.add('d-block');
            const winnerName = document.getElementById('winnerName');
            winnerName.textContent = winner;
            let winningMsg = '';
            scoreWinner = paddle1.score > paddle2.score ? paddle1.score : paddle2.score;
            scoreLoser = paddle1.score < paddle2.score ? paddle1.score : paddle2.score;
            if (winner === usernamePlayer.textContent)
                winningMsg = `<p>Congratulations, <span class="modal-username-player">${usernamePlayer.textContent}</span>! </p>
                <br>
                <p>You beat the Bot!</p>`;
            else if (winner == usernameBot.textContent)
                winningMsg = `<p>The AI (<span class="modal-username-bot">${usernameBot.textContent}</span>) wins!</p>
                <br> 
                <p>Better luck next time, <span class="modal-username-player">${usernamePlayer.textContent}</span>.</p>`;
            winnerName.innerHTML = winningMsg;
            if (localSocket && localSocket.readyState === WebSocket.OPEN && !flag_history) {
                const message = {
                    'type': 'end_single_game',
                    'winner': winner,
                    'looser': winner === usernamePlayer.textContent ? usernameBot.textContent : usernamePlayer.textContent,
                    'scoreW': scoreWinner,
                    'scoreL': scoreLoser,
                    'game': 'pong',
                    'mode': 'bot'

                };
                localSocket.send(JSON.stringify(message));
                flag_history = true;
            }
        }
    }



    document.getElementById('startGameBtn').addEventListener('click', startGame);

    function startGame() {
        flag_history = false;
        paddle1.score = 0;
        paddle2.score = 0;
        player1Score.innerHTML = paddle1.score;
        player2Score.innerHTML = paddle2.score;

        ball.pos = vec2(200, 200);

        paddle1.pos = vec2(paddleMargin, 50);
        paddle2.pos = vec2(canvas.width - paddleMargin - 20, 30);

        startGameModal.classList.remove('d-block');
        startGameModal.classList.add('d-none');

        gameOver = false;
        ball.velocity.x += velocityChange.x;
        ball.velocity.y += velocityChange.y;
        paddle1.velocity.x = paddle1VelocityChange.x;
        paddle1.velocity.y = paddle1VelocityChange.y;
        paddle2.velocity.x = paddle2VelocityChange.x;
        paddle2.velocity.y = paddle2VelocityChange.y;
        gameStarted = true;
        restartGame();
    }


    document.getElementById('pongBackToHomeBtn').addEventListener('click', backToHome);
    function backToHome() {
        flag_history = false;
        loadSection('home');
    }


    document.getElementById('pongPlayAgainBtn').addEventListener('click', restartGame);
    function restartGame() {
        flag_history = false;
        // Reset scores
        paddle1.score = 0;
        paddle2.score = 0;
        player1Score.innerHTML = paddle1.score;
        player2Score.innerHTML = paddle2.score;

        // Reset ball and paddles positions
        ball.pos = vec2(200, 200);
        ball.velocity.x = velocityChange.x;
        ball.velocity.y = velocityChange.y;
        ballPaceValue.textContent = velocity;


        paddle1.pos = vec2(paddleMargin, 50);
        paddle2.pos = vec2(canvas.width - paddleMargin - 20, 30);


        paddle1.velocity.x = paddle1VelocityChange.x;
        paddle1.velocity.y = paddle1VelocityChange.y;
        paddle2.velocity.x = paddle2VelocityChange.x;
        paddle2.velocity.y = paddle2VelocityChange.y;
        paddlePaceValue.textContent = paddleVelocity;

        // Hide game-over modal
        gameOverModal.classList.remove('d-block');
        gameOverModal.classList.add('d-none');

        // Reset gameOver flag
        gameOver = false;
        winner = '';

        // Restart the game loop
        gameLoop();
    }

}