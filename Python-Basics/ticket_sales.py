# My own practice - movie ticket sales
# Practicing variables, type checking, and basic calculations in Python

# Ticket prices
adult_price = 12.5
youth_price = 8.0

# Tickets sold
adult_tickets_sold = 20
youth_tickets_sold = 15

# Check data types
print(type(adult_price))
print(type(adult_tickets_sold))

# Calculate total revenue for each ticket type
adult_revenue = adult_price * adult_tickets_sold
youth_revenue = youth_price * youth_tickets_sold

# Total revenue
total_revenue = adult_revenue + youth_revenue

print("Adult revenue:", adult_revenue)
print("Youth revenue:", youth_revenue)
print("Total revenue:", total_revenue)
