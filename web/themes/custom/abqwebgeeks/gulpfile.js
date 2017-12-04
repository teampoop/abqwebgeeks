'use strict';

//=======================================================
// Include gulp
//=======================================================
var gulp = require('gulp');

//=======================================================
// Include Our Plugins
//=======================================================
var sass       = require('gulp-sass');
var prefix     = require('gulp-autoprefixer');
var sourcemaps = require('gulp-sourcemaps');
var sync       = require('browser-sync');
var reload     = sync.reload;
var filter     = require('gulp-filter');
var shell      = require('gulp-shell');
var imagemin   = require('gulp-imagemin');
var pngquant   = require('imagemin-pngquant');

//=======================================================
// Functions
//=======================================================
function handleError(err) {
  console.log(err.toString());
  this.emit('end');
}

//=======================================================
// Compile Our Sass
//=======================================================

gulp.task('sass', function() {
  gulp.src('./sass/{,**/}*.scss')
    .pipe(sourcemaps.init())
    .pipe(sass({
      outputStyle: 'nested'
    }))
    .on('error', handleError)
    .pipe(prefix({
      browsers: ['last 2 versions'],
      cascade: false
    }))
    .pipe(gulp.dest('css'))
    .pipe(filter('*.css'))
});

//=======================================================
// Watch and recompile sass.
//=======================================================
gulp.task('watch', function() {
  // Watch all my sass files and compile sass if a file changes.
  gulp.watch('sass/{,**/}*.scss', ['sass']);

});

//=======================================================
// Generate all styleguides
//=======================================================
gulp.task('styleguide', function() {
  return gulp.src('styleguide/*/index.html')
    .pipe(shell([
      // This basically runs the bellow command on the command line:
      // kss-node [source files to parse] [destination folder] --template [location of template files] --css [location of css to include]
      'kss-node --source <%= source %> --destination <%= destination(file.path) %> --template <%= template(file.path) %> --helpers <%= helpers %> --js <%= javascript %>'
    ], {
      templateData: {
        source: 'sass',
        helpers: 'styleguide/helpers',
        // have move up from the styleguide/dist/*/ directory
        javascript: '../../../js/dist/all.js',
        template: function (s) {
          return s.replace('/index.html', '')
        },
        destination: function (s) {
          return s.replace('/styleguide/', '/styleguide/dist/').replace('/index.html', '')
        }
      }
    }))
});

//=======================================================
// BrowserSync
//=======================================================
gulp.task('browser-sync', function() {
  sync.init({
    server: {
      baseDir: "./",
      index: "styleguide/dist/basic/index.html"
    }
  });

  //watch for changes and reload
  gulp.watch('sass/{,**/}*.scss', ['sass', 'styleguide', 'basic-kss'], sync.reload);
});

//=======================================================
// Compress assets (images, pngs, svgs).
//=======================================================

gulp.task('compress', function () {
  return gulp.src([
      'assets/src/icons/*',
      'assets/src/images/*'
    ], { base: 'assets/src/' })
    .pipe(imagemin({
      progressive: true,
      svgoPlugins: [{
        removeViewBox: false
      }],
      use: [pngquant()]
    }))
    .pipe(gulp.dest('assets/dist'));
});

//=======================================================
// Default Task
//=======================================================

gulp.task('default', ['watch']);
