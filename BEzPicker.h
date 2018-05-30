//
//  BEzPicker.h
//  EasySales
//
//  Created by julfi on 29/05/2018.
//  Copyright © 2018 Md Julfikar Mahmud.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, BEzPickerViewStyle) {
    BEzPickerViewStyle3D = 1,
    BEzPickerViewStyleFlat
};

@class BEzPicker;

@protocol BEzPickerViewDataSource <NSObject>
@required
- (NSUInteger)numberOfItemsInPickerView:(BEzPicker *)pickerView;
@optional
- (NSString *)pickerView:(BEzPicker *)pickerView titleForItem:(NSInteger)item;
- (UIImage *)pickerView:(BEzPicker *)pickerView imageForItem:(NSInteger)item;
@end

@protocol BEzPickerDelegate <UIScrollViewDelegate>
@optional
- (void)pickerView:(BEzPicker *)pickerView didSelectItem:(NSInteger)item;
- (CGSize)pickerView:(BEzPicker *)pickerView marginForItem:(NSInteger)item;
- (void)pickerView:(BEzPicker *)pickerView configureLabel:(UILabel * const)label forItem:(NSInteger)item;
@end

@interface BEzPicker : UIView

@property (nonatomic, weak) id <BEzPickerViewDataSource> dataSource;
@property (nonatomic, weak) id <BEzPickerDelegate> delegate;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, strong) UIFont *highlightedFont;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *highlightedTextColor;
@property (nonatomic, assign) CGFloat interitemSpacing;
@property (nonatomic, assign) CGFloat fisheyeFactor; // 0...1; slight value recommended such as 0.0001
@property (nonatomic, assign, getter=isMaskDisabled) BOOL maskDisabled;
@property (nonatomic, assign) BEzPickerViewStyle pickerViewStyle;
@property (nonatomic, assign, readonly) NSUInteger selectedItem;
@property (nonatomic, assign, readonly) CGPoint contentOffset;

- (void)reloadData;
- (void)scrollToItem:(NSUInteger)item animated:(BOOL)animated;
- (void)selectItem:(NSUInteger)item animated:(BOOL)animated;

@end
