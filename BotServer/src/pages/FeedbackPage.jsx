import React from "react";
import "../styles/FeedbackPage.css";

const FeedbackPage = () => {
  return (
    <div className="feedback-page">
      <main className="content">
        <section className="feedback-section">
          <h1>Feedback to the team!</h1>
          <p>
            We are thankful for the great community we have for this project. If
            there is any feedback you would like to leave us, please let us know
            below. Or, if you have any questions, we will be able to answer
            them.
          </p>

          <form className="feedback-form">
            <label htmlFor="title">Title</label>
            <input type="text" id="title" name="title" placeholder="Enter title here" />

            <label htmlFor="feedback">Feedback</label>
            <textarea
              id="feedback"
              name="feedback"
              placeholder="Enter your feedback here"
              rows="6"
            ></textarea>

            <button type="submit" className="submit-btn">
              Submit
            </button>
          </form>
        </section>
      </main>
    </div>
  );
};

export default FeedbackPage;
