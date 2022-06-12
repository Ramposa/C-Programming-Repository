from extra import extra_code

print("Start of file")

def helloWorld():
  print("Hello World!")

print("In between functions")

def main():
  print("Program starting")
  helloWorld()
  extra_code()

print("before main called")

if __name__ == "__main__":
  main()

print("after main called")