# BEzPickerView
Customisable iOS horizontal picker. Lightweight and fast 

Add the files in your project and play.

# Usage
        CGRect frame = CGRectMake(2, 210, 282, 35);
        self.pickerView = [[BEzPicker alloc] initWithFrame:frame];
        self.pickerView.delegate = self;
        self.pickerView.dataSource = self;
        self.pickerView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
        [self addSubview:self.pickerView];
    
        self.pickerView.font = [UIFont fontWithName:@"HelveticaNeue-Light" size:20];
        self.pickerView.highlightedFont = [UIFont fontWithName:@"HelveticaNeue" size:20];
        self.pickerView.backgroundColor = [UIColor whiteColor];
        self.pickerView.interitemSpacing = 20.0;
        self.pickerView.fisheyeFactor = 0.001;
        self.pickerView.pickerViewStyle = BEzPickerViewStyle3D;
        self.pickerView.maskDisabled = false;
  
Pass the frame to adjust the position and size.

        CGRect frame = CGRectMake(2, 210, 282, 35);
        self.pickerView = [[BEzPicker alloc] initWithFrame:frame];
        
Customise the font and colors. You can add background color as well.
Pass the data as following:

      self.titles = @[title,
                    @"225-200-B",
                    @"44-AA-BB-X",
                    @"RR-22-09-A",
                    @"BB-02-GH-P",
                    @"NM-YU-OP-Q",
                    @"VB-330-91-P",
                    @"NN-HU-Q1-D",
                    @"DF-90-11-HJ",
                    @"TY-WE-02-DC"];
    
    [self.pickerView reloadData];
    
 # Available functions
 
       #pragma mark - BEzPickerViewDataSource

      - (NSUInteger)numberOfItemsInPickerView:(BEzPicker *)pickerView
      {
          return [self.titles count];
      }
      - (NSString *)pickerView:(BEzPicker *)pickerView titleForItem:(NSInteger)item
      {
          return self.titles[item];
      }
      #pragma mark - BEzPickerDelegate

      - (void)pickerView:(BEzPicker *)pickerView didSelectItem:(NSInteger)item
      {
          //focused
      }

In your header file declare the delegate and datasource as following:

    @interface ViewController : UIViewController<BEzPickerDelegate,BEzPickerViewDataSource>

