<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>5.5: Image Gallery</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet">
    <style>
        .gallery img {
            width: 100%;
            height: auto;
            padding: 5px;
        }
        .modal-body img {
            width: 100%;
        }
    </style>
</head>
<body>
    <div class="container mt-5">
        <div class="row">
            <?php
            $dir = "../images/";
            $images = glob($dir . '*.{jpg,jpeg,png,gif}', GLOB_BRACE);
            foreach ($images as $image) {
                echo '<div class="col-lg-3 col-md-4 col-sm-6 mb-4">';
                echo '<div class="gallery">';
                echo '<a href="#" data-bs-toggle="modal" data-bs-target="#imageModal" data-bs-image="' . $image . '">';
                echo '<img src="' . $image . '" class="img-thumbnail">';
                echo '</a>';
                echo '</div>';
                echo '</div>';
            }
            ?>
        </div>
    </div>

    <!-- Modal -->
    <div class="modal fade" id="imageModal" tabindex="-1" aria-labelledby="imageModalLabel" aria-hidden="true">
        <div class="modal-dialog modal-lg">
            <div class="modal-content">
                <div class="modal-header">
                    <h5 class="modal-title" id="imageModalLabel">Image Preview</h5>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                </div>
                <div class="modal-body">
                    <img src="" id="modalImage" alt="Image preview">
                </div>
            </div>
        </div>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js"></script>
    <script>
        var imageModal = document.getElementById('imageModal');
        imageModal.addEventListener('show.bs.modal', function (event) {
            var button = event.relatedTarget;
            var src = button.getAttribute('data-bs-image');
            var modalImage = document.getElementById('modalImage');
            modalImage.src = src;
        });
    </script>
</body>
</html>
