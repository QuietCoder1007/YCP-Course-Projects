package edu.ycp.cs320.lab02a_llewis9.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import edu.ycp.cs320.lab02a_llewis9.controller.NumbersController;
import edu.ycp.cs320.lab02a_llewis9.model.Numbers;

public class SubtractNumbersServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {

		System.out.println("SubtractNumbers Servlet: doGet");	
		
		// call JSP to generate empty form
		req.getRequestDispatcher("/_view/subtractNumbers.jsp").forward(req, resp);
	}
	
	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		
		System.out.println("AddNumbers Servlet: doPost");
		

		// holds the error message text, if there is any
		String errorMessage = null;

		// result of calculation goes here
		Numbers model = new Numbers();
		NumbersController controller = new NumbersController();
		model.setResult(null);
		
		// decode POSTed form parameters and dispatch to controller
		try {
			model.setFirst(getDoubleFromParameter(req.getParameter("first")));
			model.setSecond(getDoubleFromParameter(req.getParameter("second")));
			model.setThird(getDoubleFromParameter(req.getParameter("third")));

			// check for errors in the form data before using is in a calculation
			if ((model.getFirst() == null && model.getSecond() == null)||
				(model.getSecond() == null && model.getThird() == null)||
				(model.getThird() == null && model.getFirst() == null)) {
				errorMessage = "Please specify at least two numbers";
			}
			// otherwise, data is good, do the calculation
			// must create the controller each time, since it doesn't persist between POSTs
			// the view does not alter data, only controller methods should be used for that
			// thus, always call a controller method to operate on the data
			else {
				//Cases to catch the users intent of picking two numbers
				if(model.getFirst() == null && model.getSecond() != null && model.getThird() != null){model.setFirst(0.0);}
				else if(model.getFirst() != null && model.getSecond() == null && model.getThird() != null){model.setSecond(0.0);}
				else if(model.getFirst() != null && model.getSecond() != null && model.getThird() == null){model.setThird(0.0);}
				controller.setModel(model);
				model.setResult(controller.subtract(model.getFirst(), model.getSecond(), model.getThird()));
			}
		} catch (NumberFormatException e) {
			errorMessage = "Invalid double";
		}
		
		// Add parameters as request attributes
		// this creates attributes named "first" and "second for the response, and grabs the
		// values that were originally assigned to the request attributes, also named "first" and "second"
		// they don't have to be named the same, but in this case, since we are passing them back
		// and forth, it's a good idea
		req.setAttribute("first", model.getFirst());
		req.setAttribute("second", model.getSecond());
		req.setAttribute("third", model.getThird());
		
		// add result objects as attributes
		// this adds the errorMessage text and the result to the response
		req.setAttribute("errorMessage", errorMessage);
		req.setAttribute("result", model.getResult());
		
		// Forward to view to render the result HTML document
		req.getRequestDispatcher("/_view/subtractNumbers.jsp").forward(req, resp);
	}

	// gets double from the request with attribute named s
	private Double getDoubleFromParameter(String s) {
		if (s == null || s.equals("")) {
			return null;
		} else {
			return Double.parseDouble(s);
		}
	}
}
